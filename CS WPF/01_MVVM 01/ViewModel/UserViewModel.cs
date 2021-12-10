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
        public RelayCommand AddUserCommand { get; set; }
        public string name { get; set; }
        public int age { get; set; }
        public UserViewModel()
        {
            Add(new UserModel() { Name = "홍길동", Age = 24 });
            AddUserCommand = new RelayCommand(AddUser);
        }

        private void AddUser(object obj)
        {
            UserViewModel user = obj as UserViewModel;
            Add(new UserModel() { Name = user.name, Age = user.age });
        }
    }
}
