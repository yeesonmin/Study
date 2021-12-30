using GMap.NET.WindowsPresentation;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _04_MVVM_GMAP.ViewModel
{
    class ViewModel_Main : INotifyPropertyChanged
    {
        GMapControl gmap;
        public GMapControl GMAP { get { return gmap; } set { gmap = value; OnPropertyChanged(); }  }
        public ViewModel_Main()
        {
            GMAP = new GMapControl();
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged([CallerMemberName] string v = null)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(v));
            }
        }
    }
}
