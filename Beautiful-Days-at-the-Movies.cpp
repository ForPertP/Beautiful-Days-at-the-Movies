int beautifulDays(int i, int j, int k)
{
    int count = 0;
    int number = 0;
    int reverse = 0;

    for (; i <= j; ++i)
    {
        number = i;
        reverse = 0;
        
        while (number != 0)
        {
            reverse = (reverse * 10) + (number % 10);
            number = number / 10;
        }
        
        if (abs(i - reverse) % k == 0)
        {
            count++;
        }
    }
    
    return count;
}
