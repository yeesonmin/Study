   M S B A M L   `   `   `  ����T  P07_DataBindling (xaml간), Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:_07_DataBindling__xaml간__07_DataBindling__xaml간_  5   	   +    %_07_DataBindling__xaml간_.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   :local(clr-namespace:_07_DataBindling__xaml간_     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5	      � .+�5
   
   �� .+�5      �� $��A��6    d� 	IsChecked 6#   �� *A+�� 5      $��B��6    6#   �� *B+�� 5      $��C��6    6#   �� *C+�� 5      -   5        $��제출��5      6"   �� 5      -   5         ��Name$
 txt1��5      ��6$   ��  �� Mode$ OneWay=��� 5      -   5        $
 txt2��5      ��6$   ��  �� Source %  System.Windows.Markup.Reference  *txt1+ �� Path$
 Text��� 5      -   5        $
 txt3��5      ��6$   �� $ TwoWay=�$
 Text��� 5      -   5        $
 txt4��5      ��6$   ��    *txt3+$
 Text� �� UpdateSourceTrigger$ PropertyChanged=�5      5      5      