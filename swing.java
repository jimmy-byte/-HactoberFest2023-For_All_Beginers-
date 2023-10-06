import javax.swing.*;  
import java.awt.*;  
import java.awt.event.*;  
import java.lang.Exception;  
  
//create CreateLoginForm class to create login form  
//class extends JFrame to create a window where our component add  
//class implements ActionListener to perform an action on button click  
class CreateLoginForm extends JFrame implements ActionListener  
{  
    //initialize button, panel, label, and text field  
    JButton b1;  
    JPanel newPanel;  
    JLabel userLabel, passLabel;  
    final JTextField  textField1, textField2;  
      
    //calling constructor  
    CreateLoginForm()  
    {     
          
      
        userLabel = new JLabel();  
        userLabel.setText("Username");       
          
  
        textField1 = new JTextField(15);      
  
   
        passLabel = new JLabel();  
        passLabel.setText("Password");       
        textField2 = new JPasswordField(15);   
          
         
        b1 = new JButton("SUBMIT"); 
          
        
        newPanel = new JPanel(new GridLayout(3, 1));  
        newPanel.add(userLabel);    
        newPanel.add(textField1);   
        newPanel.add(passLabel);   
        newPanel.add(textField2); 
        newPanel.add(b1);          
          
       
        add(newPanel, BorderLayout.CENTER);  
          
          
        b1.addActionListener(this);     
        setTitle("LOGIN FORM");         
    }  
      
    
    public void actionPerformed(ActionEvent ae)  
    {  
        String userValue = textField1.getText();       
        String passValue = textField2.getText();        
        if (userValue.equals("test1@gmail.com") && passValue.equals("test")) { 
      
            NewPage page = new NewPage();  
              
       
            page.setVisible(true);  
              
            JLabel wel_label = new JLabel("Welcome: "+userValue);  
            page.getContentPane().add(wel_label);  
        }  
        else{  
           
            System.out.println("Please enter valid username and password");  
        }  
    }  
}  
//create the main class  
class LoginFormDemo  
{  
    public static void main(String arg[])  
    {  
        try  
        {  
            //create instance of the CreateLoginForm  
            CreateLoginForm form = new CreateLoginForm();  
            form.setSize(300,100);  //set size of the frame  
            form.setVisible(true);  //make form visible to the user  
        }  
        catch(Exception e)  
        {     
     
            JOptionPane.showMessageDialog(null, e.getMessage());  
        }  
    }  
  
