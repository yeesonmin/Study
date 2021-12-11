using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _08_INotyfyPropertChanged_PropertyChanged
{
    public class User : INotifyPropertyChanged
    {
        private string firstname;
        public string FIRSTNAME
        {
            get { return firstname; }
            set
            {
                firstname = value;
                RaisePropertyChange();
            }

        }

        private string lastname;
        public string LASTNAME
        {
            get { return lastname; }
            set { 
                lastname = value;
                RaisePropertyChange();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged; 
        private void RaisePropertyChange([CallerMemberName]string propertyname = null)
        {
            if (PropertyChanged != null) 
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyname));
            }
        }
    }
}
