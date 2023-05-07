/*This doesn't work for oversized codepoints*/
#include<stdio.h>
#define LIMIT1 0x80
#define LIMIT2 0X800
#define LIMIT3 0x10000 
int main(void)
{
 int ch,codepoint,a=0,multi_counter=0,t;
 
  while((ch=getchar())!=EOF)
  {





   if((ch & LIMIT1)==0)		/*1 byte: (If first byte is 0x80)*/
   {
    codepoint=ch;
    a++;
   }



   else if((ch&0xE0)==0xC0)  /*First 3 bits:110*/
   {
 
    codepoint=(ch&0x1F);     /*Last 5 bits of 1st Byte of ch*/

    if((ch=getchar())==EOF)      /*See next byte. If EOF, print message*/
    {
     printf("Unexpected EOF.\n");
     return 1;
    }

  
    if((ch&0xC0)!=LIMIT1)    /*The first 2 bits of the 2nd Byte  aren't 10*/////
    {
     printf("Invalid UTF-8 tail byte 0x%02x\n",ch); 
     return 2;
    }  
    multi_counter++;
    codepoint<<=6;   /*codepoint=codepoint<<6*/
    codepoint+=(ch&0x3F);  /*codepoint+ Last 6 bits of ch's 2nd Byte*/
    if(codepoint<LIMIT1)
    {
     printf("Oversized UTF-8 code point:U+%04x\n",codepoint);
     return 15;
    }
   } //END OF 2BYTE CASES
 
        
  
  

     else if((ch & 0xF0)==0xE0)  //3-byte
      {
       codepoint=(ch & 0x0F);

       for(t=0;t<2;t++)
       {  
        if((ch=getchar())==EOF)
        {
         printf("Unexpexted EOF.\n");
         return 5;
        }
        if((ch & 0xC0)!=0x80)    /* first 2 bits of the 2nd byte arent 10*/
        {
         printf("Invalid UTF-8 tail byte: 0x%02x\n",ch);
         return 6;
        }
        codepoint<<=6;
        codepoint+=(ch & 0x3F);
       }

      if((codepoint>=0xD800) && (codepoint<=0xDfff))
      {
        printf("Invalid UTF-8 code point: U+%04x\n",codepoint);
        return 9;
      }
      if(codepoint<LIMIT2)
      {
       printf("Oversized UTF-8 code point:U+%04x\n",codepoint);
       return 16;
      } 

      multi_counter++;
     } //END OF 3-BYTE CASES


     else if((ch&0xF8)==(0xF0))  //4-BYTE
      {
       codepoint=(ch & 0x0F);
       for(t=0;t<3;t++)
       {
        if((ch=getchar())==EOF)
        {
         printf("Unexpexted EOF.\n");
         return 10;
        }
       if((ch & 0xC0)!=0x80)    
       {
        printf("Invalid UTF-8 tail byte: 0x%02x\n",ch);
        return 11;
       }
       codepoint<<=6;
       codepoint+=(ch & 0x3F);
      }
      if(codepoint>0x110000)
      {
       printf("Invalid UTF-8 code point: U+%04x \n",codepoint);
       return 12;
      }
      if(codepoint<LIMIT3)
      {
       printf("Oversized UTF-8 code point: U+%04x\n",codepoint);
       return 17;
      }
      multi_counter++;

    }
  
      else 
      {
       printf("Invalid header byte: 0x%02x \n",ch);
       return 13;
      }
    


   } //END OF INPUTS
  printf("Found %d ASCII and %d multi-byte UTF-8 characters.\n",a,multi_counter);
 return 0;
}

