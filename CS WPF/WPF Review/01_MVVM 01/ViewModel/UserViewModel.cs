using _01_MVVM_01.Command;
using _01_MVVM_01.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _01_MVVM_01.ViewModel
{
    class UserViewModel : INotifyPropertyChanged
    {
        private ObservableCollection<UserModel> user;
        public ObservableCollection<UserModel> User 
        {
            get { return user; }
            set
            {
                user = value;
                OnPropertyChanged();
            }
        }

        public RelayCommand AddUserCommand { get; set; }
        public string name { get; set; }
        public int age { get; set; }
        public UserViewModel()
        {
            User = new ObservableCollection<UserModel>();
            User.Add(new UserModel() { Name = "홍길동", Age = 24 });
            User.Add(new UserModel() { Name = "김길동", Age = 24 });
            AddUserCommand = new RelayCommand(AddUser);
        }

       

        public void AddUser(object obj)
        {
            UserViewModel u = obj as UserViewModel;
            User.Add(new UserModel() { Name = u.name, Age = u.age });
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
