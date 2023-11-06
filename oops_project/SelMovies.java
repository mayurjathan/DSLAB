package oops_project;

 import java.awt.*;
 import java.awt.event.*; 
 import javax.swing.*; 
 import java.awt.event.ActionListener;
 import java.awt.event.ActionEvent;
 
 public class SelMovies {
	 static JFrame f1=new JFrame("Select a Movie");
	 static ImageIcon i=new ImageIcon("my.png"); 
 static JPanel p1=new JPanel(); 
 static JPanel p2=new JPanel();
 static JPanel p3=new JPanel(); 
 static JPanel p4=new JPanel();  
 static JPanel p5=new JPanel(); 
 static JPanel p6=new JPanel();
 static JLabel l2=new JLabel("RRR:Roudram Ranam Rudhiram"); 
 static JLabel l1=new JLabel(new ImageIcon("D:\\WORK\\oops\\rrr.jpj.jpg"));  
 static JLabel l4=new JLabel("ADIPURUSH"); 
 static JLabel l3=new JLabel(new ImageIcon("D:\\WORK\\oops\\adhipursh.jpg"));
 static JLabel l6=new JLabel("PACHUVUM ATHBUTHA VILAKKUM");
 static JLabel l5=new JLabel(new ImageIcon("D:\\WORK\\oops\\pachu.jpj.jpg\\")); 
 static JLabel l8=new JLabel("ENE:EE NAGARANIKI EMAINDI"); 
 static JLabel l7=new JLabel(new ImageIcon("D:\\WORK\\oops\\ene.jpj.jpg\\")); 
 static JLabel l10=new JLabel("VIKRAM"); 
 static JLabel l9=new JLabel(new ImageIcon("D:\\WORK\\oops\\vikram.jpj.jpg\\")); 
 static JLabel l12=new JLabel("FAST X"); 
 static JLabel l13=new JLabel(new ImageIcon("D:\\WORK\\oops\\fastx.jpj.jpg\\"));  
 static JButton b1=new JButton("Book"); 
 static JButton b2=new JButton("Book");  
 static JButton b3=new JButton("Book");  
 static JButton b4=new JButton("Book"); 
 static JButton b5=new JButton("Book");
 static JButton b6=new JButton("Book"); 
 public static void main(String args[]) 
 { 
   b1.setFocusable(false); 
   b1.setBackground(new Color(0,0,90)); 
   b1.setForeground(new Color(230,240,255));   
   b2.setFocusable(false);    
   b2.setBackground(new Color(0,0,90)); 
   b2.setForeground(new Color(230,240,255)); 
   b3.setFocusable(false); 
   b3.setBackground(new Color(0,0,90)); 
   b3.setForeground(new Color(230,240,255)); 
   b4.setFocusable(false);  
   b4.setBackground(new Color(0,0,90));  
   b4.setForeground(new Color(230,240,255));  
   b5.setFocusable(false); 
   b5.setBackground(new Color(0,0,90));   
   b5.setForeground(new Color(230,240,255));   
   b6.setFocusable(false);  
   b6.setBackground(new Color(0,0,90)); 
   b6.setForeground(new Color(230,240,255)); 
   SelMovies selMovies = new SelMovies();
   b1.addActionListener(selMovies.new Action());
   b2.addActionListener(selMovies.new Action());
   b3.addActionListener(selMovies.new Action());
   b4.addActionListener(selMovies.new Action());
   b5.addActionListener(selMovies.new Action());
   b6.addActionListener(selMovies.new Action());

   p1.setLayout(new FlowLayout(FlowLayout.LEFT,30,50));  
   p1.setBackground(new Color(230,240,255)); 
   p1.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5)); 
   p2.setLayout(new FlowLayout(FlowLayout.LEFT,50,40));
   p2.setBackground(new Color(230,240,255)); 
   p2.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5));  
   p3.setLayout(new FlowLayout(FlowLayout.LEFT,25,40)); 
   p3.setBackground(new Color(230,240,255)); 
   p3.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5)); 
   p4.setLayout(new FlowLayout(FlowLayout.LEFT,50,40)); 
   p4.setBackground(new Color(230,240,255)); 
   p4.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5)); 
   p5.setLayout(new FlowLayout(FlowLayout.LEFT,50,40));
   p5.setBackground(new Color(230,240,255)); 
   p5.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5));   
   p6.setLayout(new FlowLayout(FlowLayout.LEFT,50,40));   
   p6.setBackground(new Color(230,240,255)); 
   p6.setBorder(BorderFactory.createLineBorder(new Color(0,0,90),5));   
   f1.setLayout(new GridLayout(3,2));   
   f1.setExtendedState(JFrame.MAXIMIZED_BOTH); 
   f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
   f1.setIconImage(i.getImage());   
   p1.add(l1); 
   p1.add(l2);  
   p1.add(b1);  
   p2.add(l3); 
   p2.add(l4); 
   p2.add(b2);
   p3.add(l5); 
   p3.add(l6); 
   p3.add(b3);  
   p4.add(l7);  
   p4.add(l8);  
   p4.add(b4);  
   p5.add(l9);  
   p5.add(l10); 
   p5.add(b5);  
   p6.add(l13); 
   p6.add(l12); 
   p6.add(b6);  
   f1.add(p1);  
   f1.add(p2); 
   f1.add(p3);  
   f1.add(p4);
   f1.add(p5);  
   f1.add(p6);  
   f1.setVisible(true);   
 }   
 public class Action implements ActionListener 
 {

	public void actionPerformed(ActionEvent e) {
		{ 
			 SelTheatre th=new SelTheatre();
			 if(e.getSource()==b1) 
				 th.theatre(); 
			 else if(e.getSource()==b2) 
				 th.theatre();  
			 else if(e.getSource()==b3)
				 th.theatre();
			 else if(e.getSource()==b4)
				 th.theatre(); 
			 else if(e.getSource()==b5)
				 th.theatre(); 
			 else if(e.getSource()==b6) 
				 th.theatre(); 
			 }   
			 }  
} 
}

