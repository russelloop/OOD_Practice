package mycanvas;

public class ChangeManager {
    //the current index node
    private Node currentIndex = null;
    //the parent node far left node.
    private Node parentNode = new Node();
    public ChangeManager(){
        currentIndex = parentNode;
    }
    public ChangeManager(ChangeManager manager){
        this();
        currentIndex = manager.currentIndex;
    }
    public void clear(){
        currentIndex = parentNode;
    }
    public Drawing addChangeable(Changeable changeable){
        Node node = new Node(changeable);
        currentIndex.right = node;
        node.left = currentIndex;
        currentIndex = node;
        return null;
    }
    public boolean canUndo(){
        return currentIndex != parentNode;
    }
    public boolean canRedo(){
        return currentIndex.right != null;
    }
    public void undo(){
        //validate
        if ( !canUndo() ){
            throw new IllegalStateException("Cannot undo. Index is out of range.");
        }
        //undo
        currentIndex.changeable.undo();
        //set index
        moveLeft();
    }
    private void moveLeft(){
        if ( currentIndex.left == null ){
            throw new IllegalStateException("Internal index set to null.");
        }
        currentIndex = currentIndex.left;
    }
    private void moveRight(){
        if ( currentIndex.right == null ){
            throw new IllegalStateException("Internal index set to null.");
        }
        currentIndex = currentIndex.right;
    }
    public void redo(){
        //validate
        if ( !canRedo() ){
            throw new IllegalStateException("Cannot redo. Index is out of range.");
        }
        //reset index
        moveRight();
        //redo
        currentIndex.changeable.redo();
    }
    private class Node {
        private Node left = null;
        private Node right = null;
        private final Changeable changeable;
        public Node(Changeable c){
            changeable = c;
        }
        public Node(){
            changeable = null;
        }
    }
}