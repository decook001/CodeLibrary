/*
Theory
  
  for given (a,b,c), ax+by=c has a solution for some (x,y)  <->  gcd(a,b) | c 
  where a,b,c,x,y is in Z

step 1: ax+by=c has a solution for (x,y) -> gcd(a,b) | c
proof:
let d=gcd(a,b)
d|ax, d|by 
-> d|(ax+by) 
-> d|c
-> gcd(a,b) | c

step 2:  gcd(a,b) | c  ->  ax+by=c has a solution for (x,y)

let d=gcd(a,b)
according to the extended Euclidean theorem, d=ax+by for some x,y 
c=c/d*x*a+ c/d*y*b


Solutions :
if a solution (x,y) exists then there exists an infinite number of solutions
x'=x+k*lcm(a,b)
y'=y-k*lcm(a,b)
*/

int exuclid( int a, int b, int& x, int& y )
{
    // ret=ax+by
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int g=exuclid( b, a%b, x, y );
    int tmp=y;
    y=x-(a/b)*y;
    x=tmp;
    return g;   //   g=ax+by
}


int diophantine( int a, int& x, int b, int& y, int c )
{
    int g=exuclid( a,b , x, y );
    if( c%g ) return 0;
    c/=g;
    x*=c;
    y*=c;
    return 1;
}
