using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _10_ListCollectionView
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public ListCollectionView collectionView;
        public EMP emp;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void root_DataContextChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            collectionView = (ListCollectionView)CollectionViewSource.GetDefaultView(root.DataContext);
        }

        private void EVENT_Click(object sender, RoutedEventArgs e)
        {
            var b = sender as Button;

            collectionView.SortDescriptions.Clear();

            switch (b.Name)
            {
                case "btnEmpno":
                    collectionView.SortDescriptions.Add(new System.ComponentModel.SortDescription("Empno", System.ComponentModel.ListSortDirection.Ascending));
                    break;
                case "btnName":
                    collectionView.SortDescriptions.Add(new System.ComponentModel.SortDescription("Name", System.ComponentModel.ListSortDirection.Ascending));
                    break;
                case "btnJob":
                    collectionView.SortDescriptions.Add(new System.ComponentModel.SortDescription("Job", System.ComponentModel.ListSortDirection.Ascending));
                    break;
            }
        }

        private void EVENT_Move(object sender, RoutedEventArgs e)
        {
            var b = sender as Button;

            switch (b.Name)
            {
                case "btnPre":
                    if (collectionView.MoveCurrentToPrevious())
                    {
                        emp = collectionView.CurrentAddItem as EMP;
                    }
                    else
                    {
                        collectionView.MoveCurrentToFirst();
                    }
                    break;
                case "btnNext":
                    if (collectionView.MoveCurrentToNext())
                    {
                        emp = collectionView.CurrentAddItem as EMP;
                    }
                    else
                    {
                        collectionView.MoveCurrentToLast();
                    }
                    break;
            }
        }

        private void EVENT_Filter(object sender, RoutedEventArgs e)
        {
            switch (collectionView.Filter)
            {
                case null:
                    collectionView.Filter = IsManager;
                    break;
                default:
                    collectionView.Filter = null;
                    break;
            }
        }

        private bool IsManager(object obj)
        {
            var e = obj as EMP;
            return e?.Job == "Manager";
        }
    }
}
