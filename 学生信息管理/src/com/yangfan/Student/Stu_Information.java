package com.yangfan.Student;

import java.io.*;


@SuppressWarnings("serial")
class Stu_information_class implements Serializable{
	private String stu_name = null;
	private String stu_number = null;
	private String stu_sex = null;
	private String stu_tel = null;
	public String getStu_name() {
		return stu_name;
	}
	public void setStu_name(String stu_name) {
		this.stu_name = stu_name;
	}
	public String getStu_number() {
		return stu_number;
	}
	public void setStu_number(String stu_number) {
		this.stu_number = stu_number;
	}
	public String getStu_sex() {
		return stu_sex;
	}
	public void setStu_sex(String stu_sex) {
		this.stu_sex = stu_sex;
	}
	public String getStu_tel() {
		return stu_tel;
	}
	public void setStu_tel(String stu_tel) {
		this.stu_tel = stu_tel;
	}
	
	
}


public class Stu_Information{
	public void file_save_data(Stu_information_class stu_information_class) throws IOException   {
		FileOutputStream fileOutputStream = new FileOutputStream("stu_information.bat",true);
		ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
		objectOutputStream.writeObject(stu_information_class);
		objectOutputStream.close();
		FileInputStream fileInputStream = new FileInputStream("stu_information.bat");
		ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
		try {
			stu_information_class = (Stu_information_class) objectInputStream.readObject();
		} catch (ClassNotFoundException e) {
			// TODO 自动生成的 catch 块
			System.err.println("无对象");
		} 	
		System.out.println(stu_information_class.getStu_name()+"  "+stu_information_class.getStu_number()+"  "+stu_information_class.getStu_sex()+"  "+stu_information_class.getStu_tel());
		objectInputStream.close();
	}
}
