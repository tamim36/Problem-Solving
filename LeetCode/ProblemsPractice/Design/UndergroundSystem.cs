using System;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Design
{
    public class UndergroundSystem
    {
        IDictionary<int, Tuple<string, int>> CheckInList;
        IDictionary<Tuple<string, string>, Tuple<double, int>> AverageTimeList;

        public UndergroundSystem()
        {
            CheckInList = new Dictionary<int, Tuple<string, int>>();
            AverageTimeList = new Dictionary<Tuple<string, string>, Tuple<double, int>>();
        }

        public void CheckIn(int id, string stationName, int t)
        {
            CheckInList.Add(id, Tuple.Create(stationName, t));
        }

        public void CheckOut(int id, string stationName, int t)
        {
            string startStation = CheckInList[id].Item1;
            int startTime = CheckInList[id].Item2;
            Tuple<string, string> path = Tuple.Create(startStation, stationName);
            double time = t - startTime;

            if (AverageTimeList.ContainsKey(path))
            {
                double curAverageTime = AverageTimeList[path].Item1;
                int travelNos = AverageTimeList[path].Item2;
                double updatedAverageTime = (curAverageTime * travelNos + time) / ++travelNos; 
                AverageTimeList[path] = Tuple.Create(updatedAverageTime, travelNos);
            }
            else
            {
                AverageTimeList.Add(path, Tuple.Create(time, 1));
            }

            CheckInList.Remove(id);
        }

        public double GetAverageTime(string startStation, string endStation)
        {
            return AverageTimeList[Tuple.Create(startStation, endStation)].Item1;
        }
    }
}
