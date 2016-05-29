package com.yangfan.Users;

/*
 * 票务管理系统主注册窗口
 * author:yangfan
 */
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.WindowConstants;


@SuppressWarnings("serial")
public class Output_Register extends JFrame{
	public void output(String title) {
		JFrame jFrame = new JFrame(title);
		Container container = jFrame.getContentPane();
		//标签登陆
		JLabel jLabel1 = new JLabel("登陆");
		jLabel1.setBounds(180, 120, 50, 30);
		container.add(jLabel1);
		
		//帐号标签及输入框
		JLabel jLabel2 = new JLabel("帐号");
		jLabel2.setBounds(120, 150, 50, 30);
		container.add(jLabel2);
		JTextField jTextField = new JTextField();
		jTextField.setBounds(150, 150, 100, 30);
		container.add(jTextField);
		
		//密码标签及输入框
		JLabel jLabel3 = new JLabel("密码");
		jLabel3.setBounds(120, 180, 50, 30);
		container.add(jLabel3);
		JPasswordField jpField = new JPasswordField();
		jpField.setBounds(150, 180, 100, 30);
		container.add(jpField);

		//登陆按钮
		JButton jButton1 = new JButton("登陆");
		jButton1.setBounds(120, 210, 70, 30);
		jButton1.addActionListener(new ActionListener() {
			@SuppressWarnings("resource")
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				File file = new File(jTextField.getText()+".txt");
				FileInputStream fip = null;
				try {
					fip = new FileInputStream(file);
				} catch (FileNotFoundException e1) {
					// TODO 自动生成的 catch 块
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); //默认边界布局
					jLabel1.setBackground(Color.red);
					JLabel jLabel = new JLabel("没有找到此账户",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
					return;
				}
				InputStreamReader read = null;
				try {
					read = new InputStreamReader(fip,"utf-8");
				} catch (UnsupportedEncodingException e1) {
					// TODO 自动生成的 catch 块
					e1.printStackTrace();
				}
				StringBuffer password = new StringBuffer();
				try {
					while(read.ready()){
					password.append((char)read.read());
					}
				} catch (IOException e1) {
					// TODO 自动生成的 catch 块
					e1.printStackTrace();
				}
				if(String.valueOf(password).equals(String.valueOf(jpField.getPassword()))){
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); //默认边界布局
					JLabel jLabel = new JLabel("登录成功",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
				}	
				else {
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150);
					JLabel jLabel = new JLabel("密码错误",JLabel.CENTER);
					jLabel.setLocation(100,130);
					jDialog.add(jLabel);
					jDialog.setVisible(true);
				}
			}

		});
		container.add(jButton1);
	    JButton jButton2 = new JButton("忘记密码");
		jButton2.setBounds(195, 210, 70, 30);
		container.add(jButton2);
		
		//以下
		JLabel nuLabel = new JLabel();
		nuLabel.setBounds(0,0,0,0);
		container.add(nuLabel);
		//以上
		
		
		container.setBackground(Color.white);
		jFrame.setSize(400, 600);
		jFrame.setVisible(true);
		jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

	}
		

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Output_Register().output("没人来大剧院");
	}

}
