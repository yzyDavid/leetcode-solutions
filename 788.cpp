class Solution
{
  public:
    int rotatedDigits(int N)
    {
        int i;
        int ans = 0;
        for (i = 1; i <= N; ++i)
        {
            int r = 0;
            int o = i;
            int mul = 1;
            int t = 0;
            while (o != 0)
            {
                t = o % 10;
                switch (t)
                {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                case 5:
                    t = 2 + 5 - t;
                    break;
                case 6:
                case 9:
                    t = 6 + 9 - t;
                    break;
                default:
                    goto fail;
                }
                r += mul * t;
                o /= 10;
                mul *= 10;
            }
            if (i == r)
                goto fail;
            ++ans;
        fail:;
        }
        return ans;
    }
};