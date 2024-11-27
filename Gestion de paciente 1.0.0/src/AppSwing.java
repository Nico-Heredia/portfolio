import javax.swing.*;
import java.awt.*;

public class AppSwing {
    private PacienteManager pacienteManager;

    public AppSwing() {
        pacienteManager = new PacienteManager();
        crearVentana();
    }

    private void crearVentana() {
        JFrame frame = new JFrame("Gestión de Pacientes 1.0.0");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(3, 1));
        frame.add(panel);

        JButton btnAgregar = new JButton("Agregar Paciente");
        JButton btnListar = new JButton("Listar Pacientes");
        JButton btnBuscar = new JButton("Buscar Paciente");

        panel.add(btnAgregar);
        panel.add(btnListar);
        panel.add(btnBuscar);

        btnAgregar.addActionListener(e -> mostrarFormularioAgregar());
        btnListar.addActionListener(e -> mostrarListaPacientes());
        btnBuscar.addActionListener(e -> mostrarFormularioBuscar());

        frame.setVisible(true);
    }

    private void mostrarFormularioAgregar() {
        JFrame frame = new JFrame("Agregar Paciente");
        frame.setSize(300, 300);

        JPanel panel = new JPanel(new GridLayout(10, 2));

        frame.add(panel);


        JLabel lblNombre = new JLabel("Nombre:");
        JLabel lblEdad = new JLabel("Edad:");
        JLabel lblTelefono = new JLabel("Teléfono:");
        JLabel lblDni = new JLabel("DNI:");
        JLabel lblMail = new JLabel("Email:");
        JLabel lblDiagnostico = new JLabel("Diagnóstico:");
        JTextField txtNombre = new JTextField();
        JTextField txtEdad = new JTextField();
        JTextField txtTelefono = new JTextField();
        JTextField txtDni = new JTextField();
        JTextField txtMail = new JTextField();
        JTextField txtDiagnostico = new JTextField();
        JButton btnGuardar = new JButton("Guardar");

        panel.add(lblNombre);
        panel.add(txtNombre);
        panel.add(lblEdad);
        panel.add(txtEdad);
        panel.add(lblTelefono);
        panel.add(txtTelefono);
        panel.add(lblDni);
        panel.add(txtDni);
        panel.add(lblMail);
        panel.add(txtMail);
        panel.add(lblDiagnostico);
        panel.add(txtDiagnostico);
        panel.add(new JLabel()); // Espaciador
        panel.add(btnGuardar);

        btnGuardar.addActionListener(e -> {
            try {
                String nombre = txtNombre.getText();
                int edad = Integer.parseInt(txtEdad.getText());
                Double telefono = Double.parseDouble(txtTelefono.getText());
                Double dni = Double.parseDouble(txtDni.getText());
                String mail = txtMail.getText();
                String diagnostico = txtDiagnostico.getText();

                Paciente nuevoPaciente = new Paciente(nombre, edad, telefono, dni, mail, diagnostico);
                pacienteManager.agregarPaciente(nuevoPaciente);
                JOptionPane.showMessageDialog(frame, "Paciente agregado con éxito.");
                frame.dispose();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
            }
        });

        frame.setVisible(true);
    }

    private void mostrarListaPacientes() {
        JFrame frame = new JFrame("Lista de Pacientes");
        frame.setSize(400, 300);

        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);

        for (Paciente p : pacienteManager.listarPacientes()) {
            textArea.append(p.toString() + "\n");
        }

        frame.add(new JScrollPane(textArea));
        frame.setVisible(true);
    }

    private void mostrarFormularioBuscar() {
        JFrame frame = new JFrame("Buscar Paciente");
        frame.setSize(300, 200);

        JPanel panel = new JPanel(new GridLayout(6, 2));
        frame.add(panel);

        JLabel lblNombre = new JLabel("Nombre:");
        JTextField txtNombre = new JTextField();
        JButton btnBuscar = new JButton("Buscar");

        panel.add(lblNombre);
        panel.add(txtNombre);
        panel.add(new JLabel()); // Espaciador
        panel.add(btnBuscar);

        btnBuscar.addActionListener(e -> {
            String nombre = txtNombre.getText();
            Paciente encontrado = pacienteManager.buscarPaciente(nombre);

            if (encontrado != null) {
                JOptionPane.showMessageDialog(frame, "Paciente encontrado:\n" + encontrado);
            } else {
                JOptionPane.showMessageDialog(frame, "Paciente no encontrado.");
            }
        });

        frame.setVisible(true);
    }
}

