using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemsPractice
{
    public class JwelsAndStones
    {
        public int NumJewelsInStones(string jewels, string stones)
        {
            var ans = stones.Where(c => jewels.Contains(c)).Count();
            return ans;
        }
    }
}
