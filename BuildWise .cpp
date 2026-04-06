#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

// --- Class: Material ---
class Material {
private:
    string name;
    string composition;
    string manufacturing_process;
    float price_india;
    float price_foreign;
    float import_duty;
    float shipping_charge;

public:
    Material(string n, string comp, string process,
             float pIndia, float pForeign, float duty, float ship)
        : name(n), composition(comp), manufacturing_process(process),
          price_india(pIndia), price_foreign(pForeign),
          import_duty(duty), shipping_charge(ship) {}

    void showDetails() const {
        cout << "\n-------------------------------------------------\n";
        cout << "MATERIAL: " << name << "\n";
        cout << "-------------------------------------------------\n";
        cout << "COMPOSITION: " << composition << "\n";
        cout << "PROCESS: " << manufacturing_process << "\n";

        cout << "\n--- PRICING ANALYSIS ---\n";
        cout << "Domestic Price (India): " << fixed << setprecision(2)
             << price_india << " INR per unit\n";

        float foreign_inr = price_foreign * 83.0; // Conversion
        cout << "Foreign Price (Global): " << price_foreign
             << " USD (Approx " << foreign_inr << " INR)\n";

        cout << "\nWould you like a detailed Import Cost breakdown? (1 for Yes / 0 for No): ";
        int calc;
        cin >> calc;

        if (calc == 1) {
            float import_tax = (foreign_inr * import_duty) / 100;
            float total_import_cost = foreign_inr + import_tax + shipping_charge;

            cout << "\n--- IMPORT COST BREAKDOWN ---\n";
            cout << "Base Cost:       " << foreign_inr << " INR\n";
            cout << "Import Duty (" << import_duty << "%): " << import_tax << " INR\n";
            cout << "Shipping Charge: " << shipping_charge << " INR\n";
            cout << "TOTAL LANDED COST: " << total_import_cost << " INR\n";

            if (total_import_cost > price_india) {
                cout << "\n[VERDICT]: Buying LOCALLY in India is cheaper by "
                     << total_import_cost - price_india << " INR.\n";
            } else {
                cout << "\n[VERDICT]: IMPORTING is cheaper by "
                     << price_india - total_import_cost << " INR.\n";
            }
        }
    }
};

// --- Class: Labor ---
class Labor {
private:
    string type;
    string skill_level;
    float daily_wage;

public:
    Labor(string t, string skill, float wage)
        : type(t), skill_level(skill), daily_wage(wage) {}

    void showInfo() const {
        cout << setw(20) << left << type
             << setw(35) << skill_level
             << setw(15) << fixed << setprecision(2) << daily_wage << "\n";
    }
};

// --- Class: BuildWiseApp ---
class BuildWiseApp {
private:
    vector<Material> materials;
    vector<Labor> labors;

public:
    BuildWiseApp() {
        // Initialize Materials
        materials.push_back(Material("Portland Pozzolana Cement (PPC)",
                                     "Clinker + Gypsum + Fly Ash",
                                     "Grinding clinker with gypsum and pozzolanic materials. Good for general use.",
                                     450.0, 8.0, 12.0, 50.0));

        materials.push_back(Material("TMT Steel Bars (Fe-500)",
                                     "Iron + Carbon + Manganese",
                                     "Thermo-Mechanical Treatment process. Quenching and self-tempering.",
                                     65.0, 1.2, 18.0, 10.0));

        materials.push_back(Material("Red Clay Bricks",
                                     "Alumina + Silica + Lime",
                                     "Molding clay, drying, and burning in kilns at high temperature.",
                                     12.0, 0.5, 5.0, 2.0));

        // Initialize Labors
        labors.push_back(Labor("Head Mason", "Highly Skilled - 10+ Years Exp", 1200.0));
        labors.push_back(Labor("General Helper", "Unskilled - Physical Labor", 500.0));
        labors.push_back(Labor("Site Engineer", "Professional - B.Tech Civil", 2500.0));
    }

    void mainMenu() {
        int choice;
        while (true) {
            cout << "\n--- MAIN MENU ---\n";
            cout << "1. Project Advisor (Plan a Building)\n";
            cout << "2. Material Encyclopedia (Details & Quality)\n";
            cout << "3. Labor Market Info\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: projectAdvisor(); break;
                case 2: materialEncyclopedia(); break;
                case 3: laborInfo(); break;
                case 4:
                    cout << "Exiting BuildWise. Good luck with construction!\n";
                    exit(0);
                default: cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void projectAdvisor() {
        int build_type, terrain_type;
        float area;

        cout << "\n--- STEP 1: BUILDING TYPE ---\n";
        cout << "1. Residential (Home/Apts)\n";
        cout << "2. Commercial (Shops/Malls)\n";
        cout << "3. Industrial (Factories)\n";
        cout << "Select Type: ";
        cin >> build_type;

        cout << "\n--- STEP 2: TERRAIN / LOCATION ---\n";
        cout << "1. Normal Plains\n";
        cout << "2. Hilly Area\n";
        cout << "3. Coastal / Sea Side\n";
        cout << "4. Underground\n";
        cout << "Select Terrain: ";
        cin >> terrain_type;

        cout << "\n--- STEP 3: AREA ---\n";
        cout << "Enter Total Area (sq. ft): ";
        cin >> area;

        cout << "\n\n>>> ANALYZING PROJECT REQUIREMENTS <<<\n";

        switch (terrain_type) {
            case 2:
                cout << "[ADVICE]: You are building on Hilly Terrain.\n";
                cout << " - Step foundation recommended.\n";
                cout << " - Use lightweight concrete blocks.\n";
                break;
            case 3:
                cout << "[ADVICE]: You are building near the Sea.\n";
                cout << " - Anti-corrosive coating is MANDATORY.\n";
                cout << " - Use Sulphate Resisting Cement (SRC).\n";
                break;
            case 4:
                cout << "[ADVICE]: Underground Construction.\n";
                cout << " - Heavy waterproofing required.\n";
                cout << " - Use high-grade reinforced concrete (M40).\n";
                break;
            default:
                cout << "[ADVICE]: Standard Construction.\n";
                cout << " - Brick masonry and RCC frame structure.\n";
        }

        cout << "\nDo you want to check specific material costs? (1 for Yes / 0 for No): ";
        int check;
        cin >> check;
        if (check == 1) {
            materialEncyclopedia();
        }
    }

    void materialEncyclopedia() {
        int mat_choice;
        cout << "\n--- MATERIAL ENCYCLOPEDIA ---\n";
        cout << "1. Cement (PPC)\n";
        cout << "2. Steel (TMT)\n";
        cout << "3. Bricks (Red Clay)\n";
        cout << "Enter choice: ";
        cin >> mat_choice;

        if (mat_choice < 1 || mat_choice > 3) {
            cout << "Invalid material selection.\n";
            return;
        }

        materials[mat_choice - 1].showDetails();
    }

    void laborInfo() {
        cout << "\n--- LABOR MARKET INFORMATION ---\n";
        cout << setw(20) << left << "ROLE"
             << setw(35) << "SKILL REQUIRED"
             << setw(15) << "DAILY WAGE (INR)\n";
        cout << "--------------------------------------------------------------------------\n";

        for (const auto& labor : labors) {
            labor.showInfo();
        }
        cout << "--------------------------------------------------------------------------\n";
    }
};

// --- Main Function ---
int main() {
    cout << "=================================================\n";
    cout << "   WELCOME TO BUILDWISE: CONSTRUCTION ADVISOR    \n";
    cout << "=================================================\n";

    BuildWiseApp app;
    app.mainMenu();

    return 0;
}