using _02_MVVM_ControlSizeChange.Command;
using _02_MVVM_ControlSizeChange.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _02_MVVM_ControlSizeChange.ViewModel
{
    class ViewModel_Main : INotifyPropertyChanged
    {
        /* Model_Size size;
         public Model_Size SIZE
         {
             get
             {
                 return size;
             }
             set
             {
                 size = value;
                 OnPropertyChanged();
             }
         }*/

        private double size_h;
        private double size_w;
        public double Size_height 
        { 
            get { return size_h; } 
            set 
            { 
                size_h = value; 
                Size_height2 = value / 4;  
                OnPropertyChanged(); 
            }
        }
        public double Size_Width
        { 
            get { return size_w; } 
            set
            { 
                size_w = value; 
                Size_Width2 = value / 4; 
                OnPropertyChanged();  
            } 
        }

        private double size_h2;
        private double size_w2;
        public double Size_height2 { get { return size_h2; } set { size_h2 = value; OnPropertyChanged(); } }
        public double Size_Width2 { get { return size_w2; } set { size_w2 = value; OnPropertyChanged(); } }
        public ViewModel_Main()
        {
            Size_height = 400;
            Size_Width = 400;

        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged([CallerMemberName] string v = null)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(v));
            }
        }

       /* public RelayCommand ChangedSizeCom { get; set; }
        public void ChangedSize(object obj)
        {
            Model_Size t = obj as Model_Size;
            SIZE.Size_height = t.Size_height;
            SIZE.Size_Width = t.Size_Width;
        }*/
    }
}
