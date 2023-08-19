/*
Required theories
where a,b,c,x is in Z
1. a===c (mod b) <-> a-c=bx <-> b|(a-c)  
2. a>0, a|b <-> gcd(a,b)=a
3. gcd(a,b)=c ->  a===b===0 (mod c)

Euclidean theorem says
4. a-c=bx <-> a===c (mod b) ->  gcd(a,b)=gcd(b,c)

proof:
let gcd(a,b) = g1, gcd(b,c)=g2

step 1:
g1|b -> g1|bx
g1|a, g1|bx -> g1|(a-bx) 
-> g1|c 
-> gcd(g1,c)=g1 
-> gcd(a,b,c)=g1

step 2:
g2|b -> g2|bx 
g2|bx, g2|c -> g2|(bx+c) 
-> g2|a 
-> gcd(g2,a)=g2 
-> gcd(a,b,c)=g2 

step 3:
-> g1=g2=gcd(a,b,c)
-> gcd(a,b)=gcd(b,c) 

Extended Euclidean theorem

There is some x,y in Z for which gcd(a,b)=ax+by
https://www.youtube.com/watch?v=hB34-GSDT3k

Related-

Theory:
gcd(a,b)=gcd(b,c) -> gcd(a,b)=gcd(b,c)=gcd(a,b,c)

proof:
gcd(a,b)=gcd(b,c)

-> gcd(a,b) | gcd(b,c)
-> gcd( gcd(a,b), gcd(b,c) ) = gcd(a,b) (from 2)
-> gcd( a,b,c ) = gcd(a,b)

resources - 
https://www.whitman.edu/mathematics/higher_math_online/section03.03.html
https://www.youtube.com/watch?v=cOwyHTiW4KE
*/

struct Euclid
{

    int gcd( int x, int y)
    {
        x=abs(x);
        y=abs(y);
        return y?gcd(y, x%y):x;
    }

    int lcm( int x, int y)
    {
        x=abs(x);
        y=abs(y);
        if(!x && !y) return 0;
        if( !x || !y ) return max( x,y );
        return x/gcd(x,y)*y;
    }
      
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
  
};
