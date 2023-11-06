package oops_project;
import java.awt.*; 
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*; 
public class SelSeat 
{ 
static JFrame f3=new JFrame("Select Your Seat");
static ImageIcon i=new ImageIcon("my.png"); 
static JCheckBox s1=new JCheckBox();
static JCheckBox s2=new JCheckBox();
static JCheckBox s3=new JCheckBox();
static JCheckBox s4=new JCheckBox();
static JCheckBox s5=new JCheckBox();
static JCheckBox s6=new JCheckBox();
static JCheckBox s7=new JCheckBox();
static JCheckBox s8=new JCheckBox();
static JCheckBox s9=new JCheckBox();
static JCheckBox s10=new JCheckBox(); 
static JCheckBox s11=new JCheckBox();
static JCheckBox s12=new JCheckBox(); 
static JCheckBox s13=new JCheckBox();
static JCheckBox s14=new JCheckBox();
static JCheckBox s15=new JCheckBox();
static JCheckBox s16=new JCheckBox();
static JCheckBox s17=new JCheckBox();
static JCheckBox s18=new JCheckBox();
static JCheckBox s19=new JCheckBox();
static JCheckBox s20=new JCheckBox(); 
static JCheckBox s21=new JCheckBox();
static JCheckBox s22=new JCheckBox();
static JCheckBox s23=new JCheckBox();
static JCheckBox s24=new JCheckBox();
static JCheckBox s25=new JCheckBox();
static JCheckBox s26=new JCheckBox();
static JCheckBox s27=new JCheckBox();
static JCheckBox s28=new JCheckBox();
static JCheckBox s29=new JCheckBox();
static JCheckBox s30=new JCheckBox();
static JCheckBox s31=new JCheckBox();
static JCheckBox s32=new JCheckBox();
static JCheckBox s33=new JCheckBox();
static JCheckBox s34=new JCheckBox();
static JCheckBox s35=new JCheckBox(); 
static JCheckBox s36=new JCheckBox();
static JCheckBox s37=new JCheckBox();
static JCheckBox s38=new JCheckBox();
static JCheckBox s39=new JCheckBox();
static JCheckBox s40=new JCheckBox(); 
static JLabel l=new JLabel("----------------Eyes This Way Please----------------"); 
static JButton bb1=new JButton("Book"); 
public static void seat() 
{ 
l.setForeground(new Color(0,0,90)); 
bb1.setBackground(new Color(0,0,90));
bb1.setForeground(new Color(230,240,255));
f3.setLayout(new FlowLayout(FlowLayout.CENTER,10,20)); 
f3.setSize(300,340);    f3.setResizable(false); 
   f3.getContentPane().setBackground(new Color(230,240,255)); 
   f3.setIconImage(i.getImage()); 
   f3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
   f3.setIconImage(i.getImage()); 
   bb1.setFocusable(false); 
   f3.add(s1);  
   f3.add(s2);  
   f3.add(s3);  
   f3.add(s4); 
   f3.add(s5); 
   f3.add(s6); 
   f3.add(s7); 
   f3.add(s8); 
   f3.add(s9); 
   f3.add(s10);
   f3.add(s11); 
   f3.add(s12); 
   f3.add(s13);  
   f3.add(s14);  
   f3.add(s15);  
   f3.add(s16); 
   f3.add(s17); 
   f3.add(s18); 
   f3.add(s19); 
   f3.add(s20); 
   f3.add(s21); 
   f3.add(s22); 
   f3.add(s23); 
   f3.add(s24); 
   f3.add(s25); 
   f3.add(s26); 
   f3.add(s27); 
   f3.add(s28); 
   f3.add(s29); 
   f3.add(s30); 
   f3.add(s31);  
   f3.add(s32);  
   f3.add(s33); 
   f3.add(s34);  
   f3.add(s35); 
   f3.add(s36);  
   f3.add(s37); 
   f3.add(s38);  
   f3.add(s39);  
   f3.add(s40); 
   f3.add(l);  
f3.add(bb1); 
   bb1.addActionListener(new Action()); 
   f3.setVisible(true); 
} 
static class Action implements ActionListener 
{

	public void actionPerformed(ActionEvent e) 
	{ 
		new Payment(); 
		Payment.pay(); 
		} 	
		} } 