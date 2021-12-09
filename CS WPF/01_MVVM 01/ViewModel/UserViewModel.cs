using _01_MVVM_01.Command;
using _01_MVVM_01.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_MVVM_01.ViewModel
{
    class UserViewModel : ObservableCollection<UserModel>
    {
        RelayCommand AddUserCommand { get; set; }
        public UserViewModel()
        {
            Add(new UserModel() { Name = "이선민", Age = 24 });
            AddUserCommand = new RelayCommand(AddUser);
        }

        private void AddUser(object obj)
        {
            Add(new UserModel() { Name = obj.ToString(), Age = "new" });
        }
    }
}
