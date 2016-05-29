package com.yangfan.Users;

/*
 * 票务管理系统登陆窗口
 * author:yangfan
 */
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.WindowConstants;



@SuppressWarnings("serial")
public class Output_Login extends JFrame{
	public void output() {
		JFrame jFrame = new JFrame("没人来大剧院");
		Container container = jFrame.getContentPane();
		container.setBackground(Color.white);
		//注册标签
		JLabel jLabel1 = new JLabel("注册");
		jLabel1.setBounds(180, 100, 100, 30);
		container.add(jLabel1);
		//帐号输入标签及帐号输入
		JLabel jLabel2 = new JLabel("帐号:");
		jLabel2.setBounds(120, 150, 50, 30);
		container.add(jLabel2);
		JTextField jTextField1 = new JTextField();
		jTextField1.setBounds(150, 150, 100, 30);
		container.add(jTextField1);
		//密码输入标签及密码输入与确认
		JLabel jLabel3 = new JLabel("密码:");
		jLabel3.setBounds(120, 180, 50, 30);
		container.add(jLabel3);
		JPasswordField jPasswordField1 = new JPasswordField();
		jPasswordField1.setBounds(150, 180, 100, 30);
		container.add(jPasswordField1);
		
		JLabel jLabel4 = new JLabel("密码:");
		jLabel4.setBounds(120, 210, 50, 30);
		container.add(jLabel4);
		JPasswordField jPasswordField2 = new JPasswordField();
		jPasswordField2.setBounds(150, 210, 100, 30);
		container.add(jPasswordField2);
		
		//创建一个保存按钮
		JButton jButton = new JButton("保存");
		jButton.setBounds(170, 250, 60, 30);
		container.add(jButton);
		
		//以下
		JLabel nuLabel = new JLabel();
		container.add(nuLabel);
		//以上
		
		jFrame.setSize(400, 600);
		jFrame.setVisible(true);
		jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);	
		
		
		//创建点击保存按钮事件
		jButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				if(String.valueOf(String.valueOf(jPasswordField1.getPassword())).equals(String.valueOf(jPasswordField2.getPassword()))){
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); 
					JLabel jLabel = new JLabel("注册成功",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
				}
				else {
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); 
					JLabel jLabel = new JLabel("密码不一致",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
				}
				try {
					pd_return(jTextField1,jPasswordField1, jPasswordField2);
				} catch (IOException e1) {
					// TODO 自动生成的 catch 块
					e1.printStackTrace();
				}
			}
		});
		
		
	}
	
	public void pd_return(JTextField jTextField,JPasswordField jPasswordField1,JPasswordField jPasswordField2) throws IOException {
		if(String.valueOf(jPasswordField1.getPassword()).equals(String.valueOf(jPasswordField2.getPassword())) && String.valueOf(jPasswordField2.getPassword()) != null){
			File password = new File(String.valueOf(jTextField.getText())+".txt");
			FileOutputStream fileOutputStream;
			fileOutputStream = new FileOutputStream(password);
			OutputStreamWriter writer = new OutputStreamWriter(fileOutputStream, "utf-8");
			writer.append(String.valueOf(jPasswordField1.getPassword()));
			writer.close();
			fileOutputStream.close();
		}
	}
	
	public void get_Output() {
		new Output_Login().output();
	}
}

