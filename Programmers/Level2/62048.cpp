using namespace std;

// greatest common divisor, gcd (최대 공약수)
long long gcd(int a, int b)
{
	long remainder;
    // 두 수를 분자, 분모로 두고
    long numerator = a;
    long divisor = b;
    
    // 분모가 0이 될 때 까지 나눈다.
	while (divisor != 0)
	{
		remainder = numerator % divisor;
		numerator = divisor;
		divisor = remainder;
	}
    
	return numerator;
}

long long solution(int w, int h) {
    long long W = w;    
    long long H = h;
    long long breakingSquareCnt = (w + h) - gcd(w, h);
    
    return (W * H) - breakingSquareCnt;
}