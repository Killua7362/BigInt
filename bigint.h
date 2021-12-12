#include <string>
#include <sstream>
using namespace std;

bool larger_or_smaller(string a,string b)
{
	a=a.erase(0,a.find_first_not_of('0'));
	b=b.erase(0,b.find_first_not_of('0'));
	if(a.length()>b.length())
	{
	return true;
	}
	else if(a.length()==b.length())
	{
	if((a[0]-'0')>(b[0]-'0'))
	{
	return true;
	}else{return false;}
	}else{
	return false;
	}
}

class bigint {
    private: 
        string str;         
	char sign;
    public: 
        bigint() {
            str = " "; 
	    sign='+';
        }
        bigint(const string s) {
            str = s;
	    if(str[0]=='+' || str[0]=='-')
	    {
		sign = str[0];
		str[0]='0';
	    }
        }
        bigint(long long int n) {
            str = to_string(abs(n));
	    sign=(n<0?'-':'+');
        }
        bigint(const bigint &n) {
            str = n.str;
	    sign = n.sign;
        }
	//input and output
        friend ostream &operator << (ostream& stream, const bigint &n) {
	    if(n.sign == '-')
		    stream<<n.sign;
            stream <<n.str;

            return stream;
        }

        friend istream &operator >> (istream& stream, bigint &n) {
            stream >> n.str;
            return stream;
        }

	bigint operator = (const std::string& num)
	{
	bigint temp(num);
	str = temp.str;
	sign = temp.sign;
	return *this;
	}

	bigint operator =(const bigint& num)
	{
	bigint temp(num);
	str = temp.str;
	sign=temp.sign;
	return *this;
	}

	bigint operator =(const long long int& num)
	{
	bigint temp(num);
	str = temp.str;
	sign =temp.sign;
	return *this;
	}
	//unary stff
	bigint operator +()const{
		bigint temp;
		temp = str;
		return temp;
	}

	bigint operator -()const{
		bigint temp;
		temp.str = str;
		if(temp.str!="0")
		{
			temp.sign='-';
		}
		return temp;
	}
	//addition and subtracitoin
	bigint operator + (const bigint& num)const{
	bigint result;
	result.str="";
	int carry=0,value;
	int i,j;
	string a=this->str,b=num.str;
	if(this->sign=='-' && num.sign=='+')
	{
	bigint rhs;
	rhs
	}else if(this->sign=='+' && num.sign=='-')
	{
	
	}

	if(!larger_or_smaller(a,b))
	{
	a.swap(b);
	}
	for(i=a.length()-1,j=b.length()-1;i>=0 && j>=0;i--,j--)
	{
		value=(a[i]-'0'+b[j]-'0')+carry;
		carry=value/10;
		result.str = to_string(value%10)+result.str ;
	}
	while(i>=0)
	{
		result.str = a[i]+result.str;
		i--;
	}

	if(carry!=0)
	{
	result.str = to_string(carry)+result.str;
	}
	return result;
  	}

	bigint operator - (const bigint& num)const{
	bigint result;
	result.str="";
	string a=this->str,b=num.str;
	if(!larger_or_smaller(a,b))
	{
	a.swap(b);
	result.sign='-';
	}

	int i,j,value,temp=0;
	for(i=a.length()-1,j=b.length()-1;i>=0 && j>=0;i--,j--)
	{
		temp=i-1;
		if(a[i]>b[j])
		{
		value = (a[i]-'0')-(b[j]-'0');
		result.str = to_string(value)+result.str;
		}
		else if(a[i]==b[j])
		{
		value=0;
		result.str = to_string(value)+result.str;
		}
		else if(a[i]<b[j])
		{
		while(temp>=0)
		{
			if((a[temp]-'0')>0)
			{
			a[temp]='0'+((a[temp]-'0')-1);
			break;
			}
			else if((a[temp]-'0')==0)
			{
			a[temp]='0'+ 9;
			}
			temp=temp-1;
		}
		value = 10+(a[i]-'0')-(b[j]-'0');
		result.str = to_string(value)+result.str;
		}
	}
	while(i>=0)
	{
	result.str = a[i] + result.str;
	i--;
	}
	return result;
	}
};


