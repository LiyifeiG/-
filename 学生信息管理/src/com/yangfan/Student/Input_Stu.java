package com.yangfan.Student;

import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.WindowConstants;



@SuppressWarnings("serial")
public class Input_Stu extends JFrame{
	Stu_information_class stu_Information = new Stu_information_class();
	
	
	public void output_student() {
		JFrame jFrame = new JFrame("没人来大剧院");
		Container container = jFrame.getContentPane();
		container.setBackground(Color.white);
		
		//标签1
		JLabel jLabel1 = new JLabel("输入学生信息");
		jLabel1.setBounds(150, 80, 100, 30);
		container.add(jLabel1);
		
		//标签2 学号输入
		JLabel jLabel2 = new JLabel("学号");
		jLabel2.setBounds(120, 120, 50, 30);
		container.add(jLabel2);	
		JTextField jTextField1 = new JTextField();
		jTextField1.setBounds(150, 120, 100, 30);
		container.add(jTextField1);
		
		//标签3 姓名输入
		JLabel jLabel3 = new JLabel("姓名");
		jLabel3.setBounds(120, 150, 50, 30);
		container.add(jLabel3);	
		JTextField jTextField2 = new JTextField();
		jTextField2.setBounds(150, 150, 100, 30);
		container.add(jTextField2);
		
		//标签4 性别输入
		JLabel jLabel4 = new JLabel("性别");
		jLabel4.setBounds(120, 180, 50, 30);
		container.add(jLabel4);	
		JTextField jTextField3 = new JTextField();
		jTextField3.setBounds(150, 180, 100, 30);
		container.add(jTextField3);

		
		//标签4 电话输入
		JLabel jLabel5 = new JLabel("电话");
		jLabel5.setBounds(120, 210, 50, 30);
		container.add(jLabel5);	
		JTextField jTextField4 = new JTextField();
		jTextField4.setBounds(150, 210, 100, 30);
		container.add(jTextField4);
		//保存按钮
		JButton jButton = new JButton("保存");
		jButton.setBounds(170, 260, 50, 30);
		container.add(jButton);
		jButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO 自动生成的方法存根
				stu_Information.setStu_tel(jTextField4.getText());
				stu_Information.setStu_sex(jTextField3.getText());
				stu_Information.setStu_name(jTextField2.getText());
				stu_Information.setStu_number(jTextField1.getText());

				if(stu_Information.getStu_number().length() != 0 && stu_Information.getStu_name().length() != 0 && stu_Information.getStu_sex().length() != 0 && stu_Information.getStu_tel().length() != 0){				
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); //默认边界布局
					JLabel jLabel = new JLabel("保存成功",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
					try {
						new Stu_Information().file_save_data(stu_Information);
					} catch (IOException e1) {
						// TODO 自动生成的 catch 块
						e1.printStackTrace();
					}
				}
				else{
					JDialog jDialog = new JDialog(jFrame, "", false);
					jDialog.setSize(200, 200);
					jDialog.setLocation(70, 150); //默认边界布局
					JLabel jLabel = new JLabel("有信息未填写!",JLabel.CENTER);
					jDialog.add(jLabel,"Center");
					jDialog.setVisible(true);
				}
			}
		});
		
		
		
		//并不知道什么原因的缓存占用
		JLabel jLabelnu = new JLabel("");
		jLabelnu.setBounds(400, 600, 0, 0);
		container.add(jLabelnu);
		
		jFrame.setBackground(Color.white);
		jFrame.setSize(400,600);
		jFrame.setVisible(true);
		jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		
	}
	
	
	
	
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Input_Stu().output_student();
	}

}





















