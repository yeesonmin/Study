using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_ListCollectionView
{
    public class EMP:INotifyPropertyChanged
    {
        private string job;
        private int empno;
        private string name;

        public event PropertyChangedEventHandler PropertyChanged;
        public int Empno
        {
            get
            {
                return empno;
            }

            set
            {
                empno = value;
                OnPropertyChanged("Empno");

            }
        }

        

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
                OnPropertyChanged("Name");
            }
        }

        public string Job
        {
            get
            {
                return job;
            }
            set
            {
                job = value;
                OnPropertyChanged("Job");
            }
        }

        private void OnPropertyChanged(string v)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(v));
        }
    }
}
