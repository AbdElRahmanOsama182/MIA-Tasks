from Shields import *
from Weapons import *
class Villain:
    def __init__(self, name, health=100, energy=500, shields=None, weapons=None, color="\033[1;37;40m"):
        self.name = name
        self.health = health
        self.energy = energy
        self.shields = shields if shields else []
        self.weapons = weapons if weapons else []
        self.last_save = 0
        self.color = color
    def update_gadgets(self):
        self.shields = [shield for shield in self.shields if shield.remaining_uses > 0 and self.energy >= shield.energy]
        self.weapons = [weapon for weapon in self.weapons if weapon.remaining_uses > 0 and self.energy >= weapon.energy]

    def choose(self):
        while True:
            action = input(f"{self.color}{self.name}, choose action (weapon/shield): ")
            if action == "weapon" or action == "w":
                if not self.weapons:
                    print(f"\033[1;31;40m{self.name} has no weapons. Please choose a shield.\033[1;37;40m")
                    continue
                print("Available weapons:")
                for i, weapon in enumerate(self.weapons):
                    print(f"{i + 1}. {weapon.__class__.__name__}")
                choice_index = int(input("Choose weapon: ")) - 1
                if 0 <= choice_index < len(self.weapons):
                    return self.weapons[choice_index]
                else:
                    print("\033[1;31;40mInvalid weapon choice. Please choose again.\033[1;37;40m")
            elif action == "shield" or action == "s":
                if not self.shields:
                    print(f"\033[1;31;40m{self.name} has no shields. Please choose a weapon.\033[1;37;40m")
                    continue
                print("Available shields:")
                for i, shield in enumerate(self.shields):
                    print(f"{i + 1}. {shield.__class__.__name__}")
                choice_index = int(input("Choose shield: ")) - 1
                if 0 <= choice_index < len(self.shields):
                    return self.shields[choice_index]
                else:
                    print("\033[1;31;40mInvalid shield choice. Please choose again.\033[1;37;40m")
            else:
                print("\033[1;31;40mInvalid action. Please choose again.\033[1;37;40m")

    def use(self, choice):
        self.energy -= choice.energy
        choice.remaining_uses-=1
        if isinstance(choice,Shield) or isinstance(choice,MegaMagnet):
            self.last_save = max(self.last_save,choice.save)

    def attack(self, enemy, choice):
        if isinstance(choice,KalmanMissile):
            enemy.last_save = 0
        enemy.health -= (1 - enemy.last_save) * choice.damage
        enemy.last_save = 0

class GruVillain(Villain):
    def __init__(self):
        shields = [EnergyProjectedBarrierGun(), SelectivePermeability()]
        weapons = [FreezeGun(), ElectricProd(), MegaMagnet(), KalmanMissile()]
        super().__init__("Gru", shields=shields, weapons=weapons, color="\033[1;34;40m")

class VectorVillain(Villain):
    def __init__(self):
        shields = [EnergyNetTrap(), QuantumDeflector()]
        weapons = [LaserBlasters(), PlasmaGrenades(), SonicResonanceCannon()]
        super().__init__("Vector", shields=shields, weapons=weapons, color="\033[1;35;40m")
