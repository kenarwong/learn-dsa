int gcd(int m, int n, int& numOfExecutions)
{
  numOfExecutions++;
  if (m == n)
  {
    return m;
  }

  n = n - m;

  if (m > n)
  {
    return gcd(n, m, numOfExecutions);
  }
  else
  {
    return gcd(m, n, numOfExecutions);
  }
}

int gcd2(int m, int n, int& numOfExecutions)
{
  numOfExecutions++;
  int r = n % m;
  if (r == 0)
  {
    return m;
  }

  n = r;

  if (m > n)
  {
    return gcd(n, m, numOfExecutions);
  }
  else
  {
    return gcd(m, n, numOfExecutions);
  }
}