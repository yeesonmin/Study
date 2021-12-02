using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace _09_Command01
{
    class MainViewModel
    {
        private ICommand buttonCommand;
        public ICommand ButtonCommand
        {
            get
            {
                return buttonCommand;
            }
            set
            {
                buttonCommand = value;
            }
        }

        public MainViewModel()
        {
            ButtonCommand = new RelayCommand(new Action<object>(ShowMessage));
            // = ButtonCommand = new RelayCommand((ShowMessage));
        }

        public void ShowMessage(object obj)
        {
            MessageBox.Show("Hi " + obj.ToString());
        }
    }
}
