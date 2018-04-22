#include <bits/stdc++.h>
using namespace std;
class RealNumber;
class BigInteger
{
    friend class RealNumber;
    bool sign;
    vector<int> digits;
    public:
    friend ostream &operator<<(ostream& , RealNumber );
    friend bool operator== (RealNumber a, RealNumber x);
    BigInteger()
    {
        sign=true;
        digits.push_back(0);
    }
    static BigInteger abs(BigInteger a)
    {
        a.sign=true;
        return a;
    }
    BigInteger(string s)
    {
        sign=true;
        if(s.at(0)=='-')
        {
            sign=false;
            s.erase(0,1);
        }
        for(int i =0;i<s.length();i++)
        {
            digits.push_back(s.at(i)-'0');
        }
        if(s.length()==1&&s.at(0)=='0')
        {
            sign=true;
        }
    }
    friend istream& operator>>(istream& is,BigInteger& a)
    {
        a.digits.clear();
        std::string s;
        is>>s;
        BigInteger newinteger(s);
        a=s;
        return is;
    }
    friend ostream &operator<<(ostream& os,const BigInteger& a)
    {
        if(!a.sign)
            os<<'-';
        for(int i =0;i<a.digits.size();i++)
        {
            os<<a.digits[i];
        }
        return os;
    }
   friend  bool operator== (BigInteger a, BigInteger b)
    {
        if(a.sign!=b.sign|| a.digits.size()!=b.digits.size())
        {
            return false;
        }
        else
        {
            for(int i =0;i<a.digits.size();i++)
            {
                if(a.digits[i]!=b.digits[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!= (BigInteger b)
    {
        return !((*this)==b);
    }
    void operator= (BigInteger b)
    {
        sign=b.sign;
        digits.swap(b.digits);
    }
    bool operator < (BigInteger b)
     {
         if(sign==true&&b.sign==false)
         {
             return false;
         }
         if(sign==false&&b.sign==true)
         {
             return true;
         }
         if(sign==false&&b.sign==false)
         {
             return abs(*this)>abs(b);
         }
         return b>(*this);
     }
   bool operator > (BigInteger b)
    {
        if(*this==b)
        {
            return false;
        }
        if(sign==true&&b.sign==false)
        {
            return true;
        }
        if(sign==false&&b.sign==true)
        {
            return false;
        }
        if(sign==false&&b.sign==false)
        {
            return abs(*this)<abs(b);
        }
        if(digits.size()>b.digits.size())
        {
            return true;
        }
        if(digits.size()<b.digits.size())
        {
            return false;
        }
        return !lexicographical_compare(digits.begin(),digits.end(),b.digits.begin(),b.digits.end());
    }
    bool greaterabs(BigInteger b)
    {
        return abs(*this)>abs(b);
    }
    BigInteger removezeros()
    {
        if((*this)==BigInteger("0"))
        {
            return BigInteger("0");
        }
        BigInteger copy=*this;
        while(copy.digits[copy.digits.size()-1]==0)
        {
            copy.digits.pop_back();
        }
        return copy;
    }
    BigInteger removezero()
    {
        if((*this)==BigInteger("0"))
        {
            return BigInteger("0");
        }
        BigInteger copy=*this;
        if(copy.digits[copy.digits.size()-1]==0)
        {
            copy.digits.resize(copy.digits.size()-1);
        }
        return copy;
    }
    BigInteger multiplybypoweroften(int n)
    {
        BigInteger copy=*this;
        while(n>0)
        {
            copy.digits.push_back(0);
            n--;
        }
        return copy;
    }
    BigInteger multiplybypoweroften(BigInteger n)
    {
        BigInteger copy=*this;
        while(n!=BigInteger())
        {
            copy.digits.push_back(0);
            n=n-BigInteger("1");
        }
        return copy;
    }
    BigInteger add(BigInteger b)
    {
        BigInteger ret;
        ret.digits.resize(digits.size()+1);
        int rem=0;
        for(int i =0;i<digits.size();i++)
        {
            ret.digits[digits.size()-i]+=rem;
            ret.digits[digits.size()-i]+=digits[digits.size()-i-1];
            if(b.digits.size()>i)
            {
                ret.digits[digits.size()-i]+=b.digits[b.digits.size()-i-1];
            }
            rem=ret.digits[digits.size()-i]/10;
            ret.digits[digits.size()-i]%=10;
        }
        if(rem!=0)
        {
            ret.digits[0]=rem;
        }
        else
        {
            ret.digits.erase(ret.digits.begin());
        }
        return ret;
    }
    BigInteger subtract(BigInteger b)
    {
        if(b>*this)
        {
            BigInteger ret= b.subtract(*this);
            ret.sign=false;
            return ret;
        }
        BigInteger ret;
        ret.digits.resize(digits.size()+1);
        int rem=0;
        for(int i =0;i<digits.size();i++)
        {
            ret.digits[digits.size()-i]+=rem;
            ret.digits[digits.size()-i]+=digits[digits.size()-i-1];
            if(b.digits.size()>i)
            {
                ret.digits[digits.size()-i]-=b.digits[b.digits.size()-i-1];
            }
            rem=floor(0.1*ret.digits[digits.size()-i]);
            ret.digits[digits.size()-i]=(ret.digits[digits.size()-i]+10)%10;
        }
        while(ret.digits[0]==0&&ret.digits.size()>1)
        {
            ret.digits.erase(ret.digits.begin());
        }
        return ret;
    }
    int countmult(BigInteger b)
    {
        if(b.digits.size()>digits.size())
        {
            return 0;
        }
        int ret=0;
        BigInteger temp;
        while(temp+b<(*this)||temp+b==(*this))
        {
            ret++;
            temp=temp+b;
        }
        return ret;
    }

    friend BigInteger operator+(BigInteger a,BigInteger b)
    {
        if(a<b)
        {
            swap(a,b);
        }
        if(a.sign==true&&b.sign==false)
        {
            return a.subtract(abs(b));
        }
        if(a.sign==true&&b.sign==true)
        {
            return a.add(b);
        }
        if(a.sign==false&&b.sign==false)
        {
            BigInteger ret= abs(a).add(abs(b));
            ret.sign=false;
            return ret;
        }
    }
    BigInteger operator-(BigInteger b)
    {
        b.sign=b.sign?false:true;
        return (*this)+b;
    }
    BigInteger operator*(BigInteger b)
    {
        BigInteger ret;
        for(int i =0;i<b.digits.size();i++)
        {
            BigInteger temp;
            for(int j=0;j<b.digits[b.digits.size()-i-1];j++)
            {
                temp=temp+(*this);
            }
            temp=temp.multiplybypoweroften(i);
            ret=ret+temp;
        }
        if(b.sign==false)
        {
            ret.sign=ret.sign?false:true;
        }
        return ret;
    }

    BigInteger operator/(BigInteger b)
    {
        if(b==BigInteger())
            throw;
        BigInteger ret;
        if(sign==false&&b.sign==true||sign==true&&b.sign==false)
        {
            ret.sign=false;
        }
        BigInteger temp=abs(*this);
        int len=b.digits.size();
        b=abs(b).multiplybypoweroften(temp.digits.size()-b.digits.size());
        while(1)
        {
            ret.digits.push_back(temp.countmult(b));
            temp=temp-b*BigInteger(std::string(1,'0'+temp.countmult(b)));
            if(b.removezero()!=b&&b.digits.size()>len)
                b=b.removezero();
            else
                break;
        }
        while(ret.digits[0]==0&&ret.digits.size()>1)
            ret.digits.erase(ret.digits.begin());
        if(ret.digits.size()==1&&ret.digits[0]==0)
        {
            ret.sign=true;
        }
        return ret;
    }
};
class RealNumber
{
private:
BigInteger a,b;
public:

    RealNumber()
    {
        a=BigInteger("0");
        b=BigInteger("0");
    }
    static RealNumber abs(RealNumber x)
    {
        x.a.sign=true;
        return x;
    }
    RealNumber(string s)
    {
        a.sign=true;
        if(s.at(0)=='-')
        {
            a.sign=false;
            s.erase(0,1);
        }
        int occ=s.find(".");
        if(occ!=-1)
        {
        s.erase(occ,1);
        b=BigInteger(std::string(1,'0'+s.length()-occ));
        }
        else
        {
            b=BigInteger();
        }
        BigInteger x(s);
        a=x;


        if(b>BigInteger())
        {
            b.sign=false;
        }
    }
    friend istream& operator>>(istream& is,RealNumber& a)
    {
        std::string s;
        is>>s;
        RealNumber newnumber(s);
        a=newnumber;
        return is;
    }
    friend ostream &operator<<(ostream& os, RealNumber a)
    {
        if(!a.a.sign)
            os<<'-';
        BigInteger y=a.b;
        if(a.b<BigInteger("-1")*BigInteger(std::string(1,'0'+a.a.digits.size()))||a.b==BigInteger("-1")*BigInteger(std::string(1,'0'+a.a.digits.size())))
        {
            os<<"0.";
            while(a.b!=BigInteger("-1")*BigInteger(std::string(1,'0'+a.a.digits.size())))
            {
                a.b=a.b+BigInteger("1");
                os<<"0";
            }
        }
        for(int i =0;i<a.a.digits.size();i++)
        {
            if(y==BigInteger("-1")*BigInteger(std::string(1,'0'+a.a.digits.size()-i))&&i!=0)
            {
                os<<".";
            }
            os<<a.a.digits[i];
        }
        if(y>BigInteger())
        {
            while(y!=BigInteger())
            {
                y=y-BigInteger("1");
                os<<"0";
            }
        }
        return os;
    }
    friend bool operator== (RealNumber a, RealNumber x)
    {
        if(x.b>BigInteger())
        {
            x.a=x.a*BigInteger("1").multiplybypoweroften(x.b);
        }
        else
        {
            x.b.sign=true;
            a.a=a.a*BigInteger("1").multiplybypoweroften(x.b);
        }
        if(a.b>BigInteger())
        {
            a.a=a.a*BigInteger("1").multiplybypoweroften(a.b);
        }
        else
        {
            a.b.sign=true;
            x.a=x.a*BigInteger("1").multiplybypoweroften(a.b);
        }
        return a.a==x.a;
    }
    friend bool operator!= (RealNumber a, RealNumber x)
    {
        return !(a==x);
    }
    void operator= (RealNumber x)
    {
        a=x.a;
        b=x.b;
    }
    bool operator < (RealNumber x)
     {
         return x>(*this);
     }
    bool operator > (RealNumber x)
    {
            if(x.b>BigInteger())
            {
                x.a=x.a*BigInteger("1").multiplybypoweroften(x.b);
            }
            else
            {
                x.b.sign=true;
                a=a*BigInteger("1").multiplybypoweroften(x.b);
            }
            if(b>BigInteger())
            {
                a=a*BigInteger("1").multiplybypoweroften(b);
            }
            else
            {
                b.sign=true;
                x.a=x.a*BigInteger("1").multiplybypoweroften(b);
            }
            return a>x.a;
    }
    bool greaterabs(RealNumber b)
    {
        return abs(*this)>abs(b);
    }
    friend RealNumber operator+(RealNumber a,RealNumber b)
    {
        RealNumber ret;
        if(a.b<b.b)
        {
            swap(a,b);
        }
        ret.b=b.b;
        ret.a=b.a;
        for(BigInteger exp=a.b-b.b;exp!=BigInteger("0");exp=exp-BigInteger("1"))
        {
            a.a=a.a.multiplybypoweroften(1);
        }
        ret.a=ret.a+a.a;
        return ret;
    }
    RealNumber operator-(RealNumber b)
    {
        b.a.sign=b.a.sign?false:true;
        return (*this)+b;
    }
    RealNumber operator*(RealNumber x)
    {
        RealNumber ret;
        ret.a=a*x.a;
        ret.b=b+x.b;
        return ret;
    }
    RealNumber operator/(RealNumber x)
    {
        RealNumber ret;
        ret.a=a;
        if(b>BigInteger())
        {
        ret.a=a.multiplybypoweroften(b)/x.a;
        }
        else
        {
            ret.a=a/x.a.multiplybypoweroften(b.abs(b));
        }
        ret.b=x.b;
        ret.b.sign=x.b.sign?false:true;
        return ret;
    }
};

int main()
{
    RealNumber a,b;
    cin>>a;
    cin>>b;
    cout<<a/b;
    return 0;
}

