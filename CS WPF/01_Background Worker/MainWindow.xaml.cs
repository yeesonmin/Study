using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;
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
using System.Windows.Threading;

namespace _01_Background_Worker
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {

        //백그라운드 워커 선언
        private BackgroundWorker myThread;
        private BackgroundWorker myThread2;

        //짝수의 합을 저장할 인스턴스 변수
        int sum = 0;
        public MainWindow()
        {

            InitializeComponent();
        }

        protected override void OnInitialized(EventArgs e)
        {

            base.OnInitialized(e);

            //백그라운드 워커 초기화
            //작업의 진행율이 바뀔때 ProgressChanged 이벤트 발생여부
            //작업취소 가능여부 true로 설정
            myThread = new BackgroundWorker()
            {
                WorkerReportsProgress = true,
                WorkerSupportsCancellation = true
            };

            myThread2 = new BackgroundWorker()
            {
                WorkerReportsProgress = true,
                WorkerSupportsCancellation = true
            };

            //백그라운드에서 실행될 콜백 이벤트 생성
            //For the performing operation in the background.   
            //해야할 작업을 실행할 메소드 정의
            myThread.DoWork += myThread_DoWork;
            myThread2.DoWork += myThread_DoWork2;

            //UI쪽에 진행사항을 보여주기 위해
            //WorkerReportsProgress 속성값이 true 일때만 이벤트 발생
            myThread.ProgressChanged += myThread_ProgressChanged;
            myThread2.ProgressChanged += myThread_ProgressChanged2;

            //작업이 완료되었을 때 실행할 콜백메소드 정의  
            myThread.RunWorkerCompleted += myThread_RunWorkerCompleted;
            myThread2.RunWorkerCompleted += myThread_RunWorkerCompleted2;
            MessageBox.Show("Worker 초기화");
        }

        //백그라운드 워커가 실행하는 작업
        //DoWork 이벤트 처리 메소드에서 lstNumber.Items.Add(i) 와 같은 코드를
        //직접 실행시키면 "InvalidOperationException" 오류발생
        private void myThread_DoWork(object sender, DoWorkEventArgs e)
        {
            int count = (int)e.Argument;
            for (int i = 1; i <= count; i++)
            {
                if (myThread.CancellationPending)
                {
                    e.Cancel = true;
                    return;
                }
                else
                {
                    //메인 UI쓰레드 UI를 변경하기 위해서는
                    //idle Time을 둬야한다.         
                    Thread.Sleep(10);
                    this.Dispatcher.BeginInvoke(DispatcherPriority.Normal, (ThreadStart)delegate ()
                    {
                        if (i % 2 == 0)
                        {
                            sum += i;
                            e.Result = sum;
                            lstNumber.Items.Add(i);
                        }
                    });
                    myThread.ReportProgress(i);
                }
            }
        }
        private void myThread_DoWork2(object sender, DoWorkEventArgs e)
        {
            int count = (int)e.Argument;
            for (int i = 1; i <= count; i++)
            {
                if (myThread2.CancellationPending)
                {
                    e.Cancel = true;
                    return;
                }
                else
                {
                    //메인 UI쓰레드 UI를 변경하기 위해서는
                    //idle Time을 둬야한다.         
                    Thread.Sleep(10);
                    this.Dispatcher.BeginInvoke(DispatcherPriority.Normal, (ThreadStart)delegate ()
                    {
                        if (i % 2 == 0)
                        {
                            sum += i;
                            e.Result = sum;
                            lstNumber2.Items.Add(i);
                        }
                    });
                    myThread2.ReportProgress(i);
                }
            }
        }
        //작업의 진행률이 바뀔때 발생, ProgressBar에 변경사항을 출력
        //대체로 현재의 진행상태를 보여주는 코드 여기에 작성.
        private void myThread_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressBar.Value = e.ProgressPercentage;
        }

        private void myThread_ProgressChanged2(object sender, ProgressChangedEventArgs e)
        {
            progressBar2.Value = e.ProgressPercentage;
        }

        //작업완료
        private void myThread_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled) MessageBox.Show("작업 취소...");
            else if (e.Error != null) MessageBox.Show("에러발생..." + e.Error);
            else
            {
                tblkSum.Text = ((int)e.Result).ToString();
                MessageBox.Show("작업 완료!!");
            }
        }
        private void myThread_RunWorkerCompleted2(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled) MessageBox.Show("작업 취소...");
            else if (e.Error != null) MessageBox.Show("에러발생..." + e.Error);
            else
            {
                tblkSum2.Text = ((int)e.Result).ToString();
                MessageBox.Show("작업 완료!!");
            }
        }

        private void btnStart_Click(object sender, RoutedEventArgs e)
        {
            int num;
            if (!int.TryParse(txtNumber.Text, out num))
            {
                MessageBox.Show("숫자를 입력하세요.!");
                return;
            }

            progressBar.Maximum = num;
            lstNumber.Items.Clear();
            myThread.RunWorkerAsync(num);
        }
        private void btnStart_Click2(object sender, RoutedEventArgs e)
        {
            int num;
            if (!int.TryParse(txtNumber2.Text, out num))
            {
                MessageBox.Show("숫자를 입력하세요.!");
                return;
            }

            progressBar2.Maximum = num;
            lstNumber2.Items.Clear();
            myThread2.RunWorkerAsync(num);
        }

        private void btnCancel_Click(object sender, RoutedEventArgs e)
        {
            myThread.CancelAsync();
        }
        private void btnCancel_Click2(object sender, RoutedEventArgs e)
        {
            myThread2.CancelAsync();
        }
    }
}
