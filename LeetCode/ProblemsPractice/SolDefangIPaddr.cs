using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class SolDefangIPaddr
    {
        public string DefangIPaddr(string address)
        {
            return address.Replace(".", "[.]");
        }
    }
}
