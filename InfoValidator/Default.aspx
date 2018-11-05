<%@ Page Language="C#" Inherits="InfoValidator.Default" %>
<!DOCTYPE html>
<html>
    <head runat="server">
        <title>Default</title>
        <link rel="stylesheet" href="validCss.css" type="text/css" />
    </head>
    <body>
        <form id="form1" runat="server">
            <asp:label id="name_label" Text="Username" runat="server"/>
            <br/>
            <asp:textbox id="name_text" runat="server" AutoPostBack="true"/>
            <asp:RequiredFieldValidator id="name_validator" runat="server" 
                                        ControlToValidate="name_text" ErrorMessage="*Username cant be empty." 
                                        ForeColor="red" />
            <br/>
            <asp:label id="pw_label" Text="Password" runat="server"/>
            <br/>
            <asp:textbox id="pw_text" runat="server" TextMode="Password"/>
            <asp:RequiredFieldValidator id="pw_validator" runat="server" ControlToValidate="pw_text" 
                                        ErrorMessage="*Password cant be empty." 
                                        ForeColor="red" />
            <br/>
            <asp:label id="pwc_label" Text="Comfirm" runat="server"/>
            <br/>
            <asp:textbox id="pwc_text"runat="server" TextMode="Password"/>
            <asp:RequiredFieldValidator id="pwc_validator" runat="server" ControlToValidate="pwc_text" 
                                        ErrorMessage="*Please Comfirm your password here." 
                                        ForeColor="red" />
            <asp:CompareValidator id="pwc_compare" runat="server" ControlToValidate="pwc_text" 
                                  ErrorMessage="*different from your password." ControlToCompare="pw_text" Operator="Equal" ForeColor="red"/>
            <br/>
            <asp:label id="birth_label" Text="Birthday" runat="server"/>
            <br/>
            <asp:textbox id="birth_text"runat="server"/>
            <asp:RangeValidator id="birth_range" runat="server" 
                                ControlToValidate="birth_text" ErrorMessage="*Wrong Date."
                                MaximumValue="2017-01-01" MinimumValue="1900-01-01" ForeColor="red"/>
            <br/>
            <asp:label id="tel_label" Text="Tel" runat="server"/>
            <br/>
            <asp:textbox id="tel_text"  runat="server"/>
            <asp:RegularExpressionValidator id="tel_validator" runat="server" ControlToValidate="tel_text"
                                            ValidationExpression="^\d{4}-+\d{8}$" ErrorMessage="*your phone number must be form like 0411-83225388 "
                                            ForeColor="red"/>
            <br/>                             
            <asp:label id="mail_label" Text="E-mail" runat="server"/>
            <br/>
            <asp:textbox id="mail_text"runat="server"/>
            <asp:RequiredFieldValidator id="mail_validator1" runat="server" ControlToValidate="mail_text" 
                                        ErrorMessage="*E-mail cant be empty." 
                                        ForeColor="red" />
            <asp:RegularExpressionValidator id="mail_validator2" runat="server" ControlToValidate="mail_text"
                                            ValidationExpression="^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$" ErrorMessage="*bad form"
                                            ForeColor="red"/>
            <br/> 
            <br/>
            <asp:button id="submit" runat="server" Text="submit"/> 
        </form>
    </body>
</html>

