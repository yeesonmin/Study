using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_ListCollectionView
{
    class EMPViewModel:ObservableCollection<EMP>
    {
        public EMPViewModel()
        {
            Add(new EMP() { Empno = 1, Job = "Student", Name = "홍길동" });
            Add(new EMP() { Empno = 2, Job = "Student", Name = "김길동" });
            Add(new EMP() { Empno = 3, Job = "Teacher", Name = "이길동" });
            Add(new EMP() { Empno = 4, Job = "Manager", Name = "이선민" });
        }
    }
}
