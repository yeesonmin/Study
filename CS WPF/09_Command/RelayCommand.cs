using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace _09_Command
{
    class RelayCommand:ICommand
    {
        Func<object, bool> canExecute;
        Action<object> executeAction;

        public RelayCommand(Action<object> executeAction) : this(executeAction, null)
        {

        }

        public RelayCommand(Action<object> executeAction, Func<object, bool> canExecute)
        {
            this.executeAction = executeAction ?? throw new ArgumentNullException("a");
            this.canExecute = canExecute;
        }

        public bool CanExecute(object param)
        {
            //사원이름이 없으면 버튼 비활성화
            if(param?.ToString().Length == 0)
            {
                return false;
            }

            //canExecute는 null이라 true
            bool result = this.canExecute == null ? true : this.canExecute.Invoke(param);
            return result;
        }

        //executeAction 델리게이트가 참조하고 있는 메소드는 
        //MainViewModel의 AddEmp이다.
        public void Execute(object param)
        {
            this.executeAction.Invoke(param);
        }

        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }
    }
}
