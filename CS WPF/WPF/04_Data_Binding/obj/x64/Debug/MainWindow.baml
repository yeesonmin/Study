   M S B A M L   `   `   `  ����J  F04_Data_Binding, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null3clr-namespace:_04_Data_Binding_04_Data_Binding  5   	   G(clr-namespace:_04_Data_Binding.ViewModel_04_Data_Binding.ViewModel  5   	   !    _04_Data_Binding.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   0localclr-namespace:_04_Data_Binding     5   	   7vm(clr-namespace:_04_Data_Binding.ViewModel     5   	     � Title$  
MainWindow��5	   	   $	��450��6   $	��800��6)    � 	Resources 5      '   !_04_Data_Binding.ViewModel.Duties 
  duties  
MyTemplate ��Name � ColumnDefinitions � RowDefinitions �� Path  GrayBlueGradientBrush �� 
StartPoint �� EndPoint � Color	 � Offset
 �� 
TargetType �� Property �� Value��%�  &	        &	      &	     '�� �    7    5   
   6   �� 5   
   .R�5      �� $ boder��6   ._�5      �  5      �� 5      �� 5       5      �� 5      �� 5      �� 5      .+�5      �� $��0��6    $��0��6-   $��Duty Name : ��6=   �� 5      $��0��6    $��1��6-   ��6=   �� $ DutyName��� 5      $��1��6    $��0��6-   $��Duty Type : ��6=   �� 5      $��1��6    $��1��6-   ��6=   �� $ DutyType��� 5      $��2��6    $��2��6-   5      5       5!      �� 5#   
   $	 0,0&�6<   $	 1,1&�6M   .��5$      � $ DarkGray��6   $	 0Q�6,   � 5%      $ #ccccff��6   $		 0.5Q�6+   � 5&      $ DarkGray��6   $	 1Q�6,   5'      �� 5)   
   "
 ��6   .�5*      ��  � ��8   6+   �� 5+       � ��$ 80��6&   �� 5,       � ��$ 10��6'   5-      5.      .��50      �� .+�51   
   �� -   5         ��Name$	 Add��51      $
��Auto��6   $��10q�6,   $��직무 추가��6N   �� 52   
   $��10q�6   $��직무 타입을 선택��6    �� 53   
   -   5         ��Name$
 ltb1��53      $��10q�6     �� SelectedIndex$ 0��6U   .@�54      �� .��6   Inner56      �� 57      .��6   	OutSide59      5:      �� 5<   
   $��직무��6   �� 5=   
   -   5        $
 ltb2��5=      $��10q�6    $��Stretch=�6-   #��[ 6c   ��6K   �� 5?      5@      5A      