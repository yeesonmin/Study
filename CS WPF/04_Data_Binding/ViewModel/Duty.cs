using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _04_Data_Binding.ViewModel
{
    public enum DutyType {
        Inner,
        OutSide
    }

    public class Duty
    {
        private string name;
        private DutyType dutyType;

        public string DutyName
        {
            get { return name; }
            set { name = value; }
        }

        public DutyType DutyType
        {
            get { return dutyType; }
            set { dutyType = value; }
        }
        public Duty() { }
        public Duty(string name, DutyType dutyType)
        {
            this.name = name;
            this.dutyType = dutyType;
        }
    }

    public class Duties : ObservableCollection<Duty>
    {
        public Duties()
        {
            Add(new Duty("김", DutyType.Inner));
            Add(new Duty("이", DutyType.Inner));
            Add(new Duty("박", DutyType.OutSide));
        }

    }
}
