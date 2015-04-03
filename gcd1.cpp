int gcd(int i,int j)
{
  int g=j;
  while((i%g)!=0 and (j%g)!=0)
   {
      g=g-1;
   }
  return g;
}

