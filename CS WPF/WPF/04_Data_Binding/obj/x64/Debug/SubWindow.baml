   M S B A M L   `   `   `  ����J  F04_Data_Binding, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:_04_Data_Binding_04_Data_Binding  5   	        _04_Data_Binding.SubWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   0localclr-namespace:_04_Data_Binding     5   	     � Title$  	SubWindow��5   	   $	��450��6   $	��800��6(   .��5	      � $��10q�6    � ColumnDefinitions 5
   
   �� 5      �� 5      �� 5       � RowDefinitions 5   
   �� 5      $��40 �6   �� 5      $��40 �6   �� 5      $��40 �6   �� 5      .+�5   
   �� $��20(�6   $��1��6"   $��Center=�62   $��Center=�6O   $��직무등록��6j   �� 5   
   $��1��6   $��	직무명��6!   �� 5   
   -   5         ��Name$ txtDutyName��5   /   $��1��6   $��1��6   6/   �� 5   
   $��2��6   $��직무타입��6!   	� 5   
   -   5         	�Name$ rdoInner��5      $��내근��6(   $��2��65   $��1��6B   	� 5   
   -   5        $ 
rdoOutside��5      $��외근��6*   $��2��67   $��2��6D   �� 5   
   -   5        $��1��5      $��3��6"   $��저장��6/   6<   5      5      