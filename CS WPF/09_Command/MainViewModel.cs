using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _09_Command
{
    class MainViewModel:INotifyPropertyChanged
    {
        private Emp selectEmp;
        public Emp SelectEmp
        {
            get
            {
                return selectEmp;
            }
            set
            {
                selectEmp = value;
                OnPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged([CallerMemberName] string Pname = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(Pname));
        }

        public RelayCommand AddEmpCommand { get; set; }
        public ObservableCollection<Emp> Emps { get; set; }

        public MainViewModel()
        {
            Emps = new ObservableCollection<Emp>();
            Emps.Add(new Emp { Ename = "홍길동", Job = "도적" });
            Emps.Add(new Emp { Ename = "김길동", Job = "도적2" });
            Emps.Add(new Emp { Ename = "이길동", Job = "도적3" });
            AddEmpCommand = new RelayCommand(AddEmp);
        }

        public void AddEmp(object obj)
        {
            Emps.Add(new Emp { Ename = obj.ToString(), Job = "new" });
        }
    }
}
