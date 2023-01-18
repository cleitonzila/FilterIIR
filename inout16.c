/*   16bit data input & output  */
void put16(FILE *fp, int n)    /* (int) --> file, without limiter */
{
  putc((n>>8)&0xff,fp);
  putc(n&0xff,fp);
}
void put16i(FILE *fp, int x)    /* (int) --> file,  with limiter */
{
  if(x<(-32768)) x=(-32768);
  if(x>32767) x=32767;
  putc((x>>8)&0xff,fp);
  putc(x&0xff,fp);
}
void put16d(FILE *fp, double x)    /* (double) --> file,  with limiter */
{
  int xx;
  if(x<(-32768.0)) x=(-32768.0);
  if(x>32767.0) x=32767.0;
  if(x<0.0) x-=0.5; else x+=0.5;
  xx=(int)x;
  putc((xx>>8)&0xff,fp);
  putc(xx&0xff,fp);
}
int get16(FILE *fp)       /* file --> (int), unsignd  */
{
  int m,n;
  if((n=getc(fp))==EOF) return(EOF);
  if((m=getc(fp))==EOF) return(EOF);
  return((n<<8)+m);
}
int get16i(FILE *fp, int *x)    /* file --> (int), signed */
{
  *x=get16(fp);
  if(*x==EOF) return(EOF);
  if(((*x)&0x8000)!=0) (*x)|=(~0xffff);
  return(0);
}
int get16d(FILE *fp, double *x)    /* file --> (double), signed */
{
  int n;
  n=get16(fp);
  if(n==EOF) return(EOF);
  if((n&0x8000)!=0) n|=(~0xffff);
  *x=(double)n;
  return(0);
}
