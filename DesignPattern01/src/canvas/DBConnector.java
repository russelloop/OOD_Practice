package canvas;

import java.sql.*;

public class DBConnector {
    String driver  = "com.mysql.cj.jdbc.Driver";
    private String url = "jdbc:mysql://localhost:3306/canvas?useSSL=false";
    ResultSet rs = null;
    Statement stmt = null;
    Connection connect = null;

    public void Con() {
        try {
            Class.forName(driver);  //MySQL Driver
        }
        catch(java.lang.ClassNotFoundException e){
            System.err.println(e.getMessage());
        }
    }

    public ResultSet Execute(String sql) {
        try {
            connect = DriverManager.getConnection(url,"root","SEC0132**");
            stmt = connect.createStatement();
            rs = stmt.executeQuery(sql);
        }
        catch(SQLException ex) {
            //System.err.println(ex.getMessage());
        }
        return rs;
    }

    public void Close() throws SQLException {
        rs.close();
        stmt.close();
        connect.close();
    }

}