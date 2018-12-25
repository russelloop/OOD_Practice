package canvas;

import javax.swing.*;
import java.awt.*;

public class Panel extends JPanel {
    private JTextField content;
    private JButton applyButton;
    private boolean ok;
    private JDialog dialog;
    private JComboBox fontStyle;
    private JComboBox fontSize;


    public Panel() {
        setLayout(new BorderLayout());

        String[] stlye = {"PLAIN","BOLD","ITALIC","CENTER_BASELINE"};
        String[] size = {"10","15","20","25"};

        JPanel panel = new JPanel();
        fontStyle = new JComboBox(stlye);
        fontSize = new JComboBox(size);

        panel.setLayout(new GridLayout(3, 3));
        panel.add(new JLabel("          Content:"));
        panel.add(content = new JTextField(""));
        panel.add(new JLabel("          Style:"));
        panel.add(fontStyle);
        panel.add(new JLabel("          Size:"));
        panel.add(fontSize);
        add(panel, BorderLayout.CENTER);

        applyButton = new JButton("Apply");
        applyButton.addActionListener(event -> {
            ok = true;
            dialog.setVisible(false);
        });

        JButton cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(event -> dialog.setVisible(false));

        // add buttons to southern border

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(applyButton);
        buttonPanel.add(cancelButton);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    public void setEditor(String text) {
        content.setText(text);
    }

    public Editor getEditor() {
        return new Editor(content.getText(), fontStyle.getSelectedItem().toString(), Integer.parseInt(fontSize.getSelectedItem().toString()));
    }

    public boolean showDialog(Component parent, String title) {
        ok = false;

        Frame owner = null;
        if (parent instanceof Frame)
            owner = (Frame) parent;
        else
            owner = (Frame) SwingUtilities.getAncestorOfClass(Frame.class, parent);

        // if first time, or if owner has changed, make new dialog

        if (dialog == null || dialog.getOwner() != owner) {
            dialog = new JDialog(owner, true);
            dialog.add(this);
            dialog.getRootPane().setDefaultButton(applyButton);
            dialog.pack();
        }

        dialog.setTitle(title);
        dialog.setLocation(owner.getWidth(), owner.getHeight());
        dialog.setVisible(true);
        return ok;
    }
}
