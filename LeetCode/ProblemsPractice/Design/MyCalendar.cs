using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace ProblemsPractice.Design
{
    // start time diye sort korbo -> new endtime er nearest minimum value khujte hobe -> then oite end time er sathe milaya nite hobe 
    public class MyCalendar
    {
        IList<(int, int)> sortedList;
        public MyCalendar()
        {
            sortedList = new List<(int, int)>();
        }

        public MyCalendar(IList<(int, int)> sortedList)
        {
            this.sortedList = sortedList;
        }

        private bool isValidBook(IList<(int, int)> list, int newStTime, int newEndtime)
        {
            if (list.Count == 0) return true;

            int left = 0, right = list.Count;
            
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (list[mid].Item1 >= newEndtime)
                    right = mid;
                else
                    left = mid+1;
            }

            left = left > 0 ? left - 1 : 0;
            //if (list[left].Item1 == newEndtime) return false;

            if ((list[left].Item1 < newStTime && list[left].Item2 > newStTime)
                || (list[left].Item1 < newEndtime && list[left].Item2 >= newEndtime)
                || (newStTime <= list[left].Item1 && newEndtime > list[left].Item1)
                || (newStTime < list[left].Item2 && newEndtime >= list[left].Item2))
                return false;

            return true;
        }

        private int InsertPos(IList<(int, int)> list, int newStTime)
        {
            if (list.Count == 0) return 0;

            int left = 0, right = list.Count;

            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (list[mid].Item1 > newStTime)
                    right = mid;
                else
                    left = mid + 1;
            }
            return left;
        }

        public bool Book(int start, int end)
        {
            if (isValidBook(sortedList, start, end))
            {
                int pos = InsertPos(sortedList, start);
                sortedList.Insert(pos, (start, end));
                return true;
            }
            return false;
        }
    }
}
