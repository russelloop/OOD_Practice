<%@ Page Language="C#" Inherits="ImageSalon.Default" %>
<!DOCTYPE html>
<html>
    <head runat="server">
	    <title>Default</title>
    </head>
    <body>
	    <form id="form1" runat="server">
                <asp:image runat="server" ID="Image" Width="200"></asp:image>
                <br/>
                <asp:Button ID="LastPicButton" runat="server" Text="Last" 
            onclick="LastPicButton_Click" />&nbsp;&nbsp;&nbsp;&nbsp; 
                <asp:Button ID="NextPicButton" runat="server" Text="Next" 
            onclick="NextPicButton_Click" />
                <asp:HiddenField ID="pictureIndex" Value="0" runat="server" />
	    </form>
    </body>
</html>
