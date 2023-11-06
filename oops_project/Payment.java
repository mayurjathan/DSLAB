package oops_project;
import java.awt.*;
import java.awt.event.ActionEvent; 
import java.awt.event.ActionListener; 
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import javax.swing.*; 
public class Payment 
{ 
static ImageIcon i=new ImageIcon("my.png"); 
static JFrame f4=new JFrame("Pay and Enjoy"); 
static JButton b1=new JButton("Proceed");
static JCheckBox c1=new JCheckBox("BYS Wallet"); 
static JCheckBox c2=new JCheckBox("Debit/Credit Card"); 
static JTextField t1=new JTextField(); 
static JTextField t2=new JTextField(); 
static JLabel l1 =new JLabel("Balence:0");
static JTextField t3=new JTextField(); 
static JTextField t4=new JTextField();
static JTextField t5=new JTextField();
static JTextField t6=new JTextField(); 
public static void pay() 
{ 
t1.setText("Name"); 
t1.addFocusListener(new FocusListener(){

	public void focusGained(FocusEvent e) {	
		if(t1.getText().equals("Name"))
			t1.setText(""); 
		
	}

	public void focusLost(FocusEvent e) {
		if(t1.getText().equals(""))
			t1.setText("Name"); 	
		
	}


	}); 
	t2.setText("Mobile Number");
	t2.addFocusListener(new FocusListener(){

		public void focusGained(FocusEvent e) {
			if(t2.getText().equals("Mobile Number")) 
				t2.setText(""); 
			
		}

		public void focusLost(FocusEvent e) {
			if(t2.getText().equals(""))
				t2.setText("Mobile Number"); 
			
		} 
	 
	});         
	t3.setText("Card Number"); 
	t3.addFocusListener(new FocusListener(){

		public void focusGained(FocusEvent e) {
			if(t3.getText().equals("Card Number"))
				t3.setText(""); 
			
		}

		public void focusLost(FocusEvent e) {
			if(t3.getText().equals("")) 
				t3.setText("Card Number"); 
			
		} 
	
	}); 
	t4.setText("Name On the Card");       
	t4.addFocusListener(new FocusListener(){

		public void focusGained(FocusEvent e) {
			if(t4.getText().equals("Name On the Card"))
				t4.setText(""); 
			
		}

		public void focusLost(FocusEvent e) {
			if(t4.getText().equals(""))
				t4.setText("Name On the Card"); 
			
		} 
	
	}); 
	t5.setText("Expiry Date"); 
	t5.addFocusListener(new FocusListener(){

		public void focusGained(FocusEvent e) {
			if(t5.getText().equals("Expiry Date"))
				t5.setText(""); 
			
		}

		public void focusLost(FocusEvent e) {
			if(t5.getText().equals("")) 
				t5.setText("Expiry Date"); 	
		} 
	
	}); 
	t6.setText("CVV"); 
	t6.addFocusListener(new FocusListener(){

		public void focusGained(FocusEvent e) {
			if(t6.getText().equals("CVV"))
				t6.setText(""); 
			
		}

		public void focusLost(FocusEvent e) {
			if(t6.getText().equals("")) 
				t6.setText("CVV"); 
			
		} 
	

}); 
        t1.setForeground(new Color(0,0,90));    
        t2.setForeground(new Color(0,0,90));  
        t3.setForeground(new Color(0,0,90));  
        t4.setForeground(new Color(0,0,90));   
        t5.setForeground(new Color(0,0,90));   
        t6.setForeground(new Color(0,0,90));
        b1.setBackground(new Color(0,0,90));
        b1.setForeground(new Color(230,240,255)); 
        c1.setForeground(new Color(0,0,90));
        c2.setForeground(new Color(0,0,90));
        b1.setEnabled(false); 
f4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
f4.setSize(300,300); 
f4.setLayout(new FlowLayout(FlowLayout.LEFT,10,10)); 
f4.getContentPane().setBackground(new Color(230,240,255)); 
f4.setIconImage(i.getImage());

f4.add(c1);
f4.add(c2);
f4.add(b1);
b1.setFocusable(false);
c1.addActionListener(new Action());
c2.addActionListener(new Action());
b1.addActionListener(new Action());
f4.setVisible(true); 
}
static class Action implements ActionListener 
{

	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==c1) 
		{ 
		f4.add(l1); 
		f4.revalidate(); 
		f4.repaint(); 
		b1.setEnabled(true); 
		} 
		else if(e.getSource()==c2) 
		{ 
		f4.add(t1,FlowLayout.RIGHT);
		f4.add(t2,FlowLayout.RIGHT);
		f4.add(t3,FlowLayout.RIGHT);
		f4.add(t4,FlowLayout.RIGHT);
		f4.add(t5,FlowLayout.RIGHT);
		f4.add(t6,FlowLayout.RIGHT); 
		f4.revalidate(); 
		f4.repaint();   
		b1.setEnabled(true); 
		}   
		       if(e.getSource()==b1) 
		   { 
		   JFrame f5=new JFrame("Purchase Successful"); 
		f5.setVisible(true);
		f5.setLayout(new GridLayout(1,1));
		f5.getContentPane().setBackground(new Color(230,240,255));
		f5.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		f5.setIconImage(i.getImage()); 
		f5.setSize(500,500); 
		JLabel l8=new JLabel("Payment Successful"); 
		l8.setForeground(new Color(0,0,90));
		l8.setHorizontalAlignment(JLabel.CENTER); 
		f5.add(l8); 
		f5.setVisible(true); 
		}
		}
		
	} 

}

    
