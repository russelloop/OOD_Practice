<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="fileEnter.Default" %>

<!DOCTYPE html>

<html>
    <head runat="server">
        <title>Information</title>
        <link rel="stylesheet" href="pagecss.css" type="text/css" />
    </head>
    <body>
        <div class="container">
            <form runat="server">
                <h1>Information TypeIn</h1>
                    <p>Name</p>
                    <asp:TextBox id="TextBox1" runat="server"></asp:TextBox>
                    <p>Age</p>
                    <asp:TextBox id="TextBox2" runat="server"></asp:TextBox>
                    <p>Sex</p>
                    <asp:DropDownList id="DropDownList1" runat="server">
                        <asp:ListItem Value="male"></asp:ListItem>
                        <asp:ListItem Value="female"></asp:ListItem>
                    </asp:DropDownList>
                    <p>PostCode</p>
                    <asp:TextBox id="TextBox3" runat="server"></asp:TextBox>
                    <p>Address</p>
                    <asp:TextBox id="TextBox4" runat="server"></asp:TextBox>
                    <asp:Button CssClass="button-3d button button-primary" ID="Button1" runat="server" Text="Submit" OnClick="Button1_Click" />
            </form>
        </div>
    </body>
</html>

