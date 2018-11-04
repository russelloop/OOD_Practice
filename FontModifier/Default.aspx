<%@ Page Language="C#" Inherits="FontModifier.Default" %>
<!DOCTYPE html>
<html>
    <head runat="server">
	    <title>Default</title>
    </head>
    <body>
	    <form id="form1" runat="server">
            <asp:Label id="ShowText" runat="server">Test Content</asp:Label>
            <br />
            <p>Color Select:</p>
            <asp:RadioButton id="RadioButton1" runat="server" Text="Green" AutoPostBack="true" OnCheckedChanged="RBChanged1" />
            <asp:RadioButtonList id="RadioButtonList" runat="server" AutoPostBack="true" OnSelectedIndexChanged="RBLChanged1">
                <asp:ListItem id="red" Text="Red"  Value="1" runat="server"/> 
                <asp:ListItem id="blue" Text="Blue" Value="2" runat="server" />
                <asp:ListItem id="yellow" Text="Yellow" Value="3" runat="server" />
            </asp:RadioButtonList>
            <p>Regular Style Select:</p>
            <asp:CheckBox id="CheckBox" runat="server" Text="UnderLine " AutoPostBack="true" OnCheckedChanged="CBChanged1" />
            <asp:CheckBoxList id="CheckBoxList1" runat="server" AutoPostBack="true" OnSelectedIndexChanged="CBLChanged1">
                <asp:ListItem Text="Bold" Value="1" runat="server" />
                <asp:ListItem Text="Italic" Value="2" runat="server" />
            </asp:CheckBoxList>
	    </form>
    </body>
</html>
