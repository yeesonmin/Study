using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace _09_Command01
{
    class RelayCommand:ICommand
    {
        private Action<object> action;

        public RelayCommand(Action<object> action)
        {
            this.action = action;
        }

        public event EventHandler CanExecuteChanged;

        //활성화/비활성화 동작 => 상태 변화시 CanExecuteChanged가 동작됨.
        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            //Execute 실행 시 action 동작
            action(parameter);// 여기서는 ShowMessage가 실행.
        }
    }
}
