package com.yangfan.Users;

/*
 * 票务管理系统主菜单窗口
 * author:yangfan
 */
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

@SuppressWarnings("serial")
public  class Output_Memu extends JFrame{

	public void CreatJFrame() {
		 JFrame jFrame = new JFrame("没人来大剧院");
		 Container container = jFrame.getContentPane();
		 JLabel jLabel = new JLabel("主菜单");
		 JButton jButton1 = new JButton("注册");
		 JButton jButton2 = new JButton("登陆");
		 JLabel jlLabel1 = new JLabel();
		 jLabel.setBounds(180, 120, 100, 20);
		 jButton1.setBounds(150, 160, 100, 20);
		 jButton2.setBounds(150, 190, 100, 20);
		 container.add(jLabel);
		 container.add(jButton1);
		 container.add(jButton2);
		 container.add(jlLabel1);
		 jButton1.addActionListener(new jle1());
		 jButton2.addActionListener(new jle2());
		 container.setBackground(Color.WHITE);
		 jFrame.setVisible(true);
		 jFrame.setSize(400, 600);
		 jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}
	class jle1 implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			new Output_Login().get_Output();
			// TODO 自动生成的方法存根
		}
		
	}
	class jle2 implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO 自动生成的方法存根
			new Output_Register();
			Output_Register.main(null);
		}
		
	}
	
	public static void main(String args[]) {
		new Output_Memu().CreatJFrame();
	}
}

