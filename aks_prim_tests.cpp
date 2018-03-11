bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) 
		return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
//this is just c++ implementation of above  AKS algorithm
ULL
void prime(long long int number) {
    // Establishing Variables
    long long int i = 5;
    int w = 2;
    const long long int lim = sqrt(number);

    // Gets 1, 2 and 3 out of the way
    if (number == 1) { 
	cout << number << " is hard to classify. \n";  
	return; 
	}
    if (number == 2) { cout << number << " is Prime. \n";  return; }
    if (number == 3) { cout << number << " is Prime. \n";  return; }

    // Tests Odd Ball Factors
    if (number % 2 == 0) { cout << number << " is not Prime. \n";  return; }
    if (number % 3 == 0) { cout << number << " is not Prime. \n";  return; }

    while (i <= lim) {
        if (number % i == 0) { cout << number << " is not Prime. \n";  return; }
        // Tests Number
        i = i + w; // Increments number
        w = 6 - i; // We already tested 2 and 3
        // So this removes testing multepules of this
    }
    cout << number << " is Prime. \n"; return;
}