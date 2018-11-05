<%@ Page Language="C#" Inherits="DropDownList.Default" %>
<!DOCTYPE html>
<html>
<head runat="server">
	<title>DropDownList</title>
    <link rel="stylesheet" link="DropCss.css" type="text/css" />
</head>
    <body>
	    <form id="form1" runat="server">
		    <div>
                <p>Link Select</p>
                <asp:DropDownList id="DDList1" runat="server" AutoPostBack="true" Style="width:300px; height:30px">
                    <asp:ListItem Selected="true" Value="1">Email System</asp:ListItem>
                    <asp:ListItem Value="2">Search Engine</asp:ListItem>
                    <asp:ListItem Value="3">News Website</asp:ListItem>
                </asp:DropDownList>
                <asp:DropDownList id="DDList2" runat="server" AutoPostBack="true" Style="width:300px; height:30px">
                    <asp:ListItem Value="1">https://outlook.live.com/owa</asp:ListItem>
                    <asp:ListItem Value="2">https://login.yahoo.com</asp:ListItem>
                    <asp:ListItem Value="3">https://mail.google.com</asp:ListItem>
                </asp:DropDownList>
            </div>
	    </form>
    </body>
</html>
