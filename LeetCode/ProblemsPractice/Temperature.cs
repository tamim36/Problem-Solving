using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice
{
    public class Temperature : IComparable
    {
        // The temperature value
        protected double temperatureF;

        public int CompareTo(object obj)
        {
            if (obj == null) return 1;

            Temperature otherTemperature = obj as Temperature;
            
            if (otherTemperature != null)
            {
                int val = this.temperatureF.CompareTo(otherTemperature.temperatureF);
                return val*(-1);
            }
            else
                throw new ArgumentException("Object is not a Temperature");
        }

        public double Fahrenheit
        {
            get
            {
                return this.temperatureF;
            }
            set
            {
                this.temperatureF = value;
            }
        }

        public double Celsius
        {
            get
            {
                return (this.temperatureF - 32) * (5.0 / 9);
            }
            set
            {
                this.temperatureF = (value * 9.0 / 5) + 32;
            }
        }
    }
}
